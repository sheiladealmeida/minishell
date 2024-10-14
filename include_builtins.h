/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include_builtins.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:23:28 by sheila            #+#    #+#             */
/*   Updated: 2024/10/14 16:48:03 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_H
# define MS_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <errno.h>

typedef	struct s_env
{
	char	**keys;
	char 	**values;
	int		n_env;
	struct s_env	*next;	
}	t_env;

typedef	struct s_minishell
{
	t_env	env;
	char	*cmd;
	char	**envp;
	char	**argv;
	int		e_code;
	
}	t_minishell;

#endif