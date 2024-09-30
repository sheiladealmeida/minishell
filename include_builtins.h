/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheila <sheila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:23:28 by sheila            #+#    #+#             */
/*   Updated: 2024/09/22 19:26:58 by sheila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef	struct s_minishell
{
	char **env;
}	t_minishell;

int main(int argc, char **argv);

#endif