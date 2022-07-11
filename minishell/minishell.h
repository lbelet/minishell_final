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

// ------- malloc.c -------------
char    **ft_malloc_tab(char **original);
// ------- free.c ---------------
void	ft_free_tab_simple(char **tab);
// ------- minishell_utils.c ----
void    ft_cpy_tab(char **original, char **copy);
char	*ft_strjoin_modif(char const *s1, char const s2);
// ------- signals.c ------------
void    define_input_signals(void);
// ------- code_char.c ----------
int     *ft_code_char(char *str);
// ------- split_modif.c --------
char	**ft_split_modif(char *s, char c,int *code_caractere);
// ------- one.c ----------------
void    ft_one(char *str, char **envp);
// ------- get_path.c -----------
char    *ft_path(char *str);
// ------- errors.c -------------
int	    ft_error(char *path_cmd, char **cmd_infile);
// ------- redirections_main.c --
void    ft_check_redir(int *fd, char **cmd, char **commande);
char    *ft_set_cmd(char **cmd, int *j, int i, int *code_caractere);
// ------- quotes.c -------------
char	*ft_check_quote(char **tab, int n);
void	ft_check_quote_simple(char *tab);
// ------- dollar.c -------------
char    *ft_check_dollars(char *str, char **envp, int *code_caractere);
// ------- code_char.c ----------
int     ft_open_quote(char  *str, int i, int *code_char);



#endif