/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheila <sheila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:25:14 by sheila            #+#    #+#             */
/*   Updated: 2025/01/09 01:59:45 by sheila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	creat_pid(void)
{
	pid_t	child;

	child = fork();
	if (child < 0)
	{
		perror_msg("ERROR", "fork");
		g_e_code = 127;
	}
	return (child);
}

void	run_cmd(t_minishell *mshell, t_cmd *cmd, int *prev_fd)
{
	g_e_code = 0;
	if (*prev_fd != -1)
		redir_fds(*prev_fd, STDIN_FILENO);
	if (cmd->next)
		redir_fds(cmd->fd[1], STDOUT_FILENO);
	if (handle_redir(mshell, &(cmd->tokens)))
	{
		if (cmd->fd[0] != -1)
			close(cmd->fd[0]);
		if (is_builtin(cmd))
			run_builtin(mshell, cmd);
		else
			run_execve(mshell, cmd->tokens);
	}
	else
	{
		if (cmd->fd[0] != -1)
			close(cmd->fd[0]);
	}
	close(mshell->heredoc_fd);
	close(mshell->initial_fds[0]);
	close(mshell->initial_fds[1]);
	clear_mshell(mshell);
	exit(g_e_code);
}

void	exec_child(t_minishell *mshell, t_cmd *cmd, int *prev_fd)
{
	pid_t	pid;

	pid = creat_pid();
	if (pid == 0)
		run_cmd(mshell, cmd, prev_fd);
	if (*prev_fd != -1)
		close(*prev_fd);
	if (cmd->next)
		close(cmd->fd[1]);
	*prev_fd = cmd->fd[0];
	mshell->child[mshell->i++] = pid;
}

void	exec_multi_cmds(t_minishell *mshell)
{
	t_cmd	*cmd;
	int		prev_fd;
	int		n_cmds;

	cmd = mshell->commands;
	prev_fd = -1;
	n_cmds = get_ncmds(mshell->commands);
	mshell->i = 0;
	while (cmd)
	{
		signal(SIGINT, SIG_IGN);
		if (cmd->tokens && has_heredoc(mshell, &(cmd->tokens)))
		{
			open_hd(mshell);
			if (g_e_code == 130)
				return ;
			prev_fd = mshell->heredoc_fd;
		}
		exec_child(mshell, cmd, &prev_fd);
		cmd = cmd->next;
	}
	wait_childs(mshell, n_cmds);
	check_exit_status(mshell);
}

void	handle_exec(t_minishell *mshell)
{
	save_original_fds(mshell->initial_fds);
	create_pipes(mshell->commands);
	if (mshell->commands && !mshell->commands->next)
	{
		if (has_heredoc(mshell, &mshell->commands->tokens))
		{
			open_hd(mshell);
			if (g_e_code == 0)
				redir_fds(mshell->heredoc_fd, STDIN_FILENO);
		}
		if (handle_redir(mshell, &(mshell->commands->tokens)))
		{
			if (is_builtin(mshell->commands))
				run_builtin(mshell, mshell->commands);
			else
				run_execve(mshell, mshell->commands->tokens);
		}
	}
	else
		exec_multi_cmds(mshell);
	if (mshell->heredoc_fd != -1)
		close(mshell->heredoc_fd);
	recover_original_fds(mshell->initial_fds);
}
