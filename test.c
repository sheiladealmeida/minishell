/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheila <sheila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:09:28 by sheila            #+#    #+#             */
/*   Updated: 2024/09/23 15:50:46 by sheila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


void display_environment()
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

    char **key = env;
    
    // Itera sobre as variáveis conhecidas e tenta imprimir seus valores
    while (*key != NULL) {
        char *value = getenv(*key);
        if (value != NULL) {
            printf("%s=%s\n", *key, value);
        } else {
            printf("%s not set\n", *key);
        }
        key++;
    }
}

int main() {
    // Exibe todas as variáveis de ambiente definidas em env_variables
    display_environment();

    return 0;
}