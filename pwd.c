/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:20:19 by shrodrig          #+#    #+#             */
/*   Updated: 2024/10/09 11:40:29 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include_builtins.h"

//obter o caminho atual
int ft_pwd(void)
{
    char pwd[PATH_MAX]; //tamanho maximo do caminho
    if (getcwd(pwd, sizeof(pwd)) != NULL)
        ft_putstr_fd(pwd, STDOUT_FILENO);
    else
		perror("pwd");//printar a mensaem de erro padrao. 
    return (1);
}

int main(void)
{
	ft_pwd();
	return (0);
}