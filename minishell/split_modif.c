/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_modif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santonie <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:46:58 by santonie          #+#    #+#             */
/*   Updated: 2022/06/15 16:53:43 by santonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_get_nbr_word_modif(const char *str, char c, int *code_caractere)
{
	int	nbr;
	int	verif;
	int	i;

	verif = 0;
	nbr = 0;
	i = 0;
	while (*str != '\0')
	{
		if (*str == c && code_caractere[i] == 6)
		{
			verif = 0;
			str++;
			i++;
			continue ;
		}
		if (!verif)
		{
			verif = 1;
			nbr++;
		}
		str++;
		i++;
	}
	return (nbr);
}

void	ft_free_tab_modif(char **tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void ft_index(int *k, int *j)
{
	*k = *k + 1;
	*j = *j + 1;
}

void	ft_get_words_modif(char **tab, char *str, char c, int n)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < n)
	{
		j = 0;
		while (*str == c && (ft_code_char(str)[k]) == 6)
		{
			str++;
			k++;
		}
		while ((*(str + j) && *(str + j) != c) || (*(str + j) == c
				&& (ft_code_char(str))[k] != 6))
			ft_index(&k, &j);
		tab[i] = ft_substr(str, 0, j);
		if (!tab[i])
		{
			ft_free_tab_modif(tab, i - 1);
			return ;
		}
		str += j;
		i++;
	}
}

char	**ft_split_modif(char *s, char c,int *code_caractere)
{
	int		n;
	char	**tab;

	if (!s)
		return (NULL);
	n = ft_get_nbr_word_modif(s, c, code_caractere);
	tab = malloc((n + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab[n] = NULL;
	ft_get_words_modif(tab, s, c, n);
	return (tab);
}
