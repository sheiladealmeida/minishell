/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheila <sheila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:09:28 by sheila            #+#    #+#             */
/*   Updated: 2025/01/12 14:56:37 by sheila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_options(t_token *tokens, char *cmd_name)
{
	t_token	*temp;

	temp = tokens;
	if (!(ft_strcmp(cmd_name, "unset")) || !(ft_strcmp(cmd_name, "export")))
	{
		if (!temp->next)
			return (false);
		temp = temp->next;
		if (ft_strncmp(temp->input, "-", 1) == 0)
		{
			g_e_code = 1;
			error_msg(tokens->input, "no support for options", 1);
			return (true);
		}
	}
	return (false);
}

void	run_builtin(t_minishell *mshell, t_cmd *commands)
{
	char	*cmd_name;

	cmd_name = handle_quotes(commands->tokens->input, 0, 0);
	if (!check_options(commands->tokens, cmd_name))
	{
		if (!(ft_strcmp(cmd_name, "cd")))
			ft_cd(mshell, commands->tokens);
		else if (!(ft_strcmp(cmd_name, "echo")))
			ft_echo(mshell, commands->tokens);
		else if (!(ft_strcmp(cmd_name, "env")))
			ft_env(mshell->env, commands->tokens);
		else if (!(ft_strcmp(cmd_name, "exit")))
			ft_exit(mshell, commands->tokens, cmd_name);
		else if (!(ft_strcmp(cmd_name, "export")))
			ft_export(mshell, commands->tokens);
		else if (!(ft_strcmp(cmd_name, "pwd")))
			ft_pwd(mshell, commands->tokens);
		else if (!(ft_strcmp(cmd_name, "unset")))
			ft_unset(mshell, commands->tokens);
	}
	if (cmd_name)
		free(cmd_name);
	return ;
}

int	is_builtin(t_cmd *commands)
{
	char	*cmd_name;

	if (!commands || !commands->tokens)
		return (0);
	cmd_name = handle_quotes(commands->tokens->input, 0, 0);
	if (!(ft_strcmp(cmd_name, "cd")) || !(ft_strcmp(cmd_name, "echo"))
		|| !(ft_strcmp(cmd_name, "env")) ||!(ft_strcmp(cmd_name, "exit"))
		||!(ft_strcmp(cmd_name, "export")) || !(ft_strcmp(cmd_name, "pwd"))
		|| (!(ft_strcmp(cmd_name, "unset"))))
	{
		free(cmd_name);
		return (1);
	}
	if (cmd_name)
		free(cmd_name);
	return (0);
}

void	cd_minus(t_minishell *mshell, char **path)
{
	*path = go_path(mshell, "OLDPWD");
	if (*path)
		ft_putendl_fd(*path, STDOUT_FILENO);
}
