/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:56:31 by shrodrig          #+#    #+#             */
/*   Updated: 2024/10/14 17:06:04 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include_builtins.h"

void ft_unset(t_minishell *mshell, char *var)
{
    int i = 0;
    size_t len = ft_strlen(var);
    
    if (!*var)
        return (0);
    while (mshell->env.keys[i])
    {
        if (strncmp(mshell->env.keys[i], var, len) == 0 && mshell->env.keys[i][len] == '=')
        {
            
            return;
        }
        i++;
    }
}

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    t_minishell mshell;
    
    int i = 0;
    init_struct(&mshell, &mshell.env, envp);
	ft_unset(&mshell, argv[2]);
    return 0;
}