/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:09:28 by sheila            #+#    #+#             */
/*   Updated: 2024/10/07 18:15:45 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "include_builtins.h"


void init_env(t_minishell *mshell)
{
   char *env[] = {"SYSTEMD_EXEC_PID", "SSH_AUTH_SOCK", "SESSION_MANAGER",
    "GNOME_TERMINAL_SCREEN", "LANG", "LANGUAGE", "XDG_CURRENT_DESKTOP", "FT_HOOK_NAME", "FT_HOOK_PATHNAME",
    "XDG_GREETER_DATA_DIR", "LIBVIRT_DEFAULT_URI", "GPG_AGENT_INFO", "DESKTOP_SESSION", "QT_IM_MODULE",
    "XDG_MENU_PREFIX", "XDG_SESSION_PATH", "PWD", "USER", "DBUS_SESSION_BUS_ADDRESS", "DOCKER_HOST",
    "SSH_AGENT_LAUNCHER", "GTK_MODULES", "XDG_CONFIG_DIRS", "GTK_IM_MODULE", "XDG_SESSION_DESKTOP",
    "QT_ACCESSIBILITY", "GNOME_DESKTOP_SESSION_ID", "KRB5CCNAME", "XDG_SEAT_PATH", "LOGNAME", "GNOME_TERMINAL_SERVICE",
    "PATH", "XDG_RUNTIME_DIR", "XDG_DATA_DIRS", "XMODIFIERS", "SHELL", "XDG_SESSION_TYPE", "DBUS_STARTER_BUS_TYPE", "HOME",
    "VTE_VERSION", "GDM_LANG", "COLORTERM", "XAUTHORITY", "DBUS_STARTER_ADDRESS", "DISPLAY", "TERM", "GDMSESSION", 
    "XDG_SESSION_CLASS", "SHLVL", "OLDPWD", "ZSH", "PAGER", "LESS", "LSCOLORS", "LS_COLORS", NULL };
    char    **key = env;
    char    *value;
    static int  i;
    
    while (*key!= NULL)
    {
        value = getenv(*key);
        if (value != NULL)
        {
            mshell->keys[i] = ft_strdup(*key);
            mshell->values[i] = ft_strdup(value);
            i++;
        }
        key++;
    }
    mshell->n_env = i;
}

void    init_mshell(t_minishell *mshell)
{
    mshell->keys = (char **)malloc(sizeof(char *) * 60);
    mshell->values = (char **)malloc(sizeof(char *) * 60);
}

void    print(t_minishell *mshell)
{
    int i = 0;
    while(i <= mshell->n_env)
    {
        if (mshell->values != NULL)
            printf("%s=%s\n", mshell->keys[i], mshell->values[i]);
        else
            printf("%s not set\n", mshell->keys[i]);
        i++;
    }
}

int main()
{
    t_minishell mshell;

    init_mshell(&mshell);
    get_env(&mshell);
    print(&mshell);
    return 0;
}
