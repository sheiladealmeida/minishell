/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesilva- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:50:22 by jesilva-          #+#    #+#             */
/*   Updated: 2024/11/27 09:50:26 by jesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	err_val(char *str)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	g_e_code = 2;
	return (1);
}

static int	check_del(char *arg, int *was_cmd, int *i)
{
	if (arg[*i] == '|')
	{
		if (!val_pipe(arg, was_cmd, i) || !was_cmd)
			return (err_val("syntax error near unexpected token `|'"));
	}
	if (arg[*i] == '>')
	{
		if (!val_red(arg, was_cmd, i))
			return (err_val("syntax error near unexpected token  `>'"));
	}
	if (arg[*i] == '<')
	{
		if (!val_red_in(arg, was_cmd, i))
			return (err_val("syntax error near unexpected token  `<'"));
	}
	if (arg[*i] == '"' || arg[*i] == '\'')
	{
		if (!val_quot(arg, i))
			return (err_val("syntax error quote not closed"));
	}
	if (arg[*i] == '&' && arg[*i + 1] == '&')
		return (err_val("syntax error near unexpected token `&'"));
	return (0);
}

int	val_sintax(char *arg)
{
	int	was_cmd;
	int	i;

	i = 0;
	was_cmd = 0;
	if (!arg)
		return (1);
	while (arg[i])
	{
		if (!arg)
			return (1);
		if (check_del(arg, &was_cmd, &i))
			return (1);
		if (arg[i] != ' ')
			was_cmd = 1;
		if (arg[i] != '\0')
			i++;
		else
			break ;
	}
	return (0);
}
