/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:05:19 by sheila            #+#    #+#             */
/*   Updated: 2024/10/09 11:20:51 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include_builtins.h"


/*int ft_pwd(void)
{
    char pwd[_PC_PATH_MAX];
    if (getcwd(pwd, sizeof(pwd)) != NULL)
        ft_putstr_fd(pwd, STDOUT_FILENO);
    else
		perror("pwd");
    return (1);
}

int ft_echo(char **argv)
{
    int newline = 1;
	int	i = 1;
    if (argv[1] && ft_strncmp(argv[1], "-n", 3) == 0)
	{
        newline = 0;
        i++;
    }
    while(argv[i])
	{
        ft_putstr_fd(argv[i], STDOUT_FILENO);
        if (argv[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
    }
    if (newline)
	    ft_putstr_fd("\n", STDOUT_FILENO);
    return (0);
}

int	is_num(char *str)
{
    if(!str)
        return (0);
    else
    {
	    while (*str)
	    {
	    	if (!(*str >= '0' && *str <= '9'))
	    		return (0);
	    	str++;
	    }
    }
	return (1);
}

void    ft_exit(char **argv)
{
	//FREE?
	if (argv[1] && argv[2] != NULL)
		ft_putstr_fd("exit\nexit: too many arguments", STDOUT_FILENO);
    else if (argv[1] && !is_num(argv[1]))
		ft_putstr_fd("exit\nnumeric argument required", STDOUT_FILENO);
	else if (argv[1])
    {
        //TRATAR %256
		exit(ft_atoi(argv[1]));
    }
    else
        exit(0);
}

void init_env(t_minishell *mshell)
{
   int i;
   
   i = 0;

   
}

void ft_unset(t_minishell *mshell, char *var)
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