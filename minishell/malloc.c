#include "minishell.h"

char    **ft_malloc_tab(char **original)
{
    int i;
    char **sorted;

    i = 0;
    while (original[i])
        i++;
    sorted = malloc((i + 1) *sizeof(char *));
    sorted[i] = NULL;
    return (sorted);
}