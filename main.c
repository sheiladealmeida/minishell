/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:05:19 by sheila            #+#    #+#             */
/*   Updated: 2024/10/14 16:56:05 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include_builtins.h"

/*void ft_unset(t_minishell *mshell, char *var)
{
    int i = 0;
    size_t len = ft_strlen(var);
    
    if (!*var)
        return (0);
    while (mshell->keys[i])
    {
        if (strncmp(mshell->keys[i], var, len) == 0 && mshell->keys[i][len] == '=')
        {
            ft_bzero(mshell->keys[i], len);
            ft_bzero(mshell->values[i], sizeof(mshell->values[i]));
            return;
        }
        i++;
    }
}

int ft_export(t_minishell *mshell, char *args)
{
    if (args[1] != NULL)
    {
        char *key = NULL;
        char *value = NULL;
        char *var = ft_strchr(args[1], '=');

        if (var)
        {
            int key_len = var - args[1];
            key = malloc(key_len + 1);
            if (!key)
            {
                ft_putstr_fd("Error: malloc", STDOUT_FILENO);
                return 1;
            }
            ft_strncpy(key, args[1], key_len);
            key[key_len] = '\0';

            value = ft_strdup(var + 1);
            if (!value)
            {
                ft_putstr_fd("Error: strdup", STDOUT_FILENO);
                free(key);
                return 1;
            }
        }
        else
            ft_putstr_fd("Erro: formato inválido. Use KEY=VALUE\n", STDOUT_FILENO);
        free(key);
        free(value);
    }
    else
        ft_putstr_fd("Erro: Nenhum argumento fornecido. Use KEY=VALUE\n", STDOUT_FILENO);
    return 1;
}*/

int main(int argc, char **argv, char **envp)
{
    ft_exit(argv);
    return 0;
}