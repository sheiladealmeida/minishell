/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:42:24 by shrodrig          #+#    #+#             */
/*   Updated: 2024/10/09 15:02:36 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include_builtins.h"

int ft_echo(t_minishell *mshell)
{
    int newline = 1;
	int	i = 1;
    if (mshell->argv[1] && ft_strncmp(mshell->argv[1], "-n", 3) == 0)
	{
        newline = 0;
        i++;
    }
    while(mshell->argv[i])
	{
        ft_putstr_fd(mshell->argv[i], STDOUT_FILENO);
        if (mshell->argv[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
    }
    if (newline)
	    ft_putstr_fd("\n", STDOUT_FILENO);
    return (0);
}

int main(int argc, char **argv)
{
	(void)argc;
    t_minishell mshell;
    ft_bzero(&mshell, sizeof(mshell));
    argv++;
	mshell.argv = argv;
    ft_echo(&mshell);
	return(0);
}

