#include "minishell.h"

void	ft_free_tab_simple(char **tab)
{
	int	i;
	int n;

	n =0;
	i = 0;
	while (tab[n])
		n++;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}