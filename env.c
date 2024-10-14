/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:56:58 by shrodrig          #+#    #+#             */
/*   Updated: 2024/10/14 17:06:44 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include_builtins.h"

void init_env(t_minishell *mshell)
{
    int i;
    char **key;
    char *value;

    mshell->env.keys = (char **)malloc(sizeof(char *) * (mshell->env.n_env + 1));
    mshell->env.values = (char **)malloc(sizeof(char *) * (mshell->env.n_env + 1));
    if (!mshell->env.keys || !mshell->env.values)
        return;

    i = 0;
    while (mshell->envp[i])
    {
        key = ft_split(mshell->envp[i], '=');
        if (key[0] != NULL)
            mshell->env.keys[i] = ft_strdup(key[0]);
		/*if (key[1] != NULL)
        {
            value = ft_strjoin("=", key[1]);  // Adicionar o '=' de volta
            mshell->env.values[i] = ft_strdup(value);
            free(value);  // Liberar a memória alocada temporariamente
        }*/
        value = ft_strchr(mshell->envp[i], '=');
        if (value != NULL)
            mshell->env.values[i] = ft_strdup(value);
        //printf("Key: %s, Value: %s\n", mshell->env.keys[i], mshell->env.values[i]);
        free(key[0]);
        free(key[1]);
        free(key);
		free(value);
        i++;
    }
    mshell->env.keys[i] = NULL;
    mshell->env.values[i] = NULL; 
}

void    init_struct(t_minishell *mshell, t_env *env, char **envp)
{
    static int i;
    
    ft_bzero(mshell, sizeof(t_minishell));
    ft_bzero(env, sizeof(t_env));
    while(envp[i])
        i++;
    mshell->envp = (char **)malloc(sizeof(char *) * (i +1));
    if(!mshell->envp)
        return;
    mshell->env.n_env = i;
    i = 0;
    while(envp[i])
    {
        mshell->envp[i] = ft_strdup(envp[i]);
        i++;
    }
    mshell->envp[i] = NULL;
    init_get(mshell);
}

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    t_minishell mshell;
    
    int i = 0;
    init_struct(&mshell, &mshell.env, envp);
    
    // while(mshell.envp[i])
    //     printf("%s\n", mshell.envp[i++]);
    return 0;
}