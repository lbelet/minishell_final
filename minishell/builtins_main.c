#include "minishell.h"

int ft_check_builtins(char **cmd)
{
    if (ft_strncmp(cmd[0], "echo", 4) == 0)
        return (1);
    else if (ft_strncmp(cmd[0], "exit", 4) == 0)
        return (1);
    else if (ft_strncmp(cmd[0], "pwd", 3) == 0)
        return (1);
    else if (ft_strncmp(cmd[0], "env", 3) == 0)
        return (1);
    else if (ft_strncmp(cmd[0], "cd", 2) == 0)
        return (1);
    else if (ft_strncmp(cmd[0], "export", 6) == 0)
        return (1);
    else if (ft_strncmp(cmd[0], "unset", 5) == 0)
        return (1);
    return (0);
}

