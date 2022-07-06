#include "minishell.h"

void ft_cpy_tab(char **original, char **copy)
{
    int i;

    i = 0;
    while (original[i])
    {
        copy[i] = ft_strdup(original[i]);
        i++;        
    }
}
