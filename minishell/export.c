#include "minishell.h"

char    **ft_export(char **cmd_test, char **envp, char **args)
{
    int i;
    int j;
    char **envp_sorted;
    char **new_args;
    char **tmp;

    j = 0;
    i = 0;
    envp_sorted = ft_malloc_env(envp);
    if (!envp_sorted)
        return NULL;
    if (ft_nbr_args(cmd_test) == 0)
    {
        while (envp[i])
        {
            envp_sorted[i] = ft_strdup(envp[i]);
            i++;
        }
        ft_sort_alpha(envp_sorted);
        ft_printf_all(envp_sorted);
        if (args)
        {
            ft_sort_alpha(args);
            ft_printf_all(args);
        }
    }
    if (ft_nbr_args(cmd_test) > 0)
    {
        new_args = ft_malloc_var(cmd_test);
        if (!new_args)
            return NULL;
        while (i < ft_nbr_args(cmd_test))
        {
            new_args[i] = ft_strdup(cmd_test[i + 1]);
            i++;
        }
        if (!args)
        {
            ft_sort_alpha(new_args);
            args = ft_malloc_env(new_args);
            i = 0;
            while (new_args[i])
            {
                args[i] = ft_strdup(new_args[i]);
                i++;
            }
        }
        else if (args[0])
        {
            tmp = ft_malloc_env(args);
            i = 0;
            while (args[i])
            {
                tmp[i] = ft_strdup(args[i]);
                free(args[i]);
                i++;
            }
            free(args);
            args = malloc((i + ft_nbr_args(cmd_test) + 1) * sizeof(char *));
            args[i + ft_nbr_args(cmd_test) + 1] = NULL;
            i = 0;
            while (tmp[i])
            {
                args[i] = ft_strdup(tmp[i]);
                i++;
            }
            while (j < ft_nbr_args(cmd_test))
            {
                args[i + j] = ft_strdup(cmd_test[j + 1]);
                j++;
            }
        }
    }
    return (args);
}