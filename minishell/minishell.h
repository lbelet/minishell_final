#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdbool.h>
#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdarg.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <limits.h>
#include <dirent.h>

void    ft_cpy_tab(char **original, char **copy);
char    **ft_malloc_tab(char **original);
void    define_input_signals(void);
void	ft_free_tab_simple(char **tab);
int     *ft_code_char(char *str);
char	**ft_split_modif(char *s, char c,int *code_caractere);

#endif