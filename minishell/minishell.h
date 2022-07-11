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

typedef struct s_var
{
    char    **nos_variables;
}           t_var;



// ------- malloc.c -------------
char    **ft_malloc_tab(char **original);
// ------- free.c ---------------
void	ft_free_tab_simple(char **tab);
// ------- minishell_utils.c ----
void    ft_cpy_tab(char **original, char **copy);
char	*ft_strjoin_modif(char const *s1, char const s2);
// ------- signals.c ------------
void    define_input_signals(void);
// ------- split_modif.c --------
char	**ft_split_modif(char *s, char c,int *code_caractere);
// ------- one.c ----------------
void    ft_one(char *str, char **envp);
// ------- get_path.c -----------
char    *ft_path(char *str);
// ------- errors.c -------------
int	    ft_error(char *path_cmd, char **cmd_infile);
void    ft_error_fd(int fd, char *infile);
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
int     *ft_code_char(char *str);
// ------- builtins_main.c ------
int     ft_check_builtins(char **cmd);
void    ft_execute_builtins(char **cmd_test, char **envp);
int     ft_execute_builtins_fd(int fd_out, char **cmd_test);
// ------- echo.c ---------------
int ft_echo(char **cmd_test);
int ft_echo_fd(int fd_out, char **cmd_test);
// ------- redir_in_out.c -------
void ft_exec_in_out(int *fd, char **commande, char **envp);
void ft_files(char **cmd, int *fd, int *j, int *i);
char *ft_set_file(char **cmd, int *j, int i);
// ------- redir_in.c -----------
void ft_exec_in(int fd_in, char **commande, char **envp);
void ft_infile_split(char **cmd, int *fd, int *i);
void ft_infile_nosplit(char **cmd, int *fd, int *j, int i);
// ------- redir_out.c ----------
void ft_exec_out(int fd_out, char **commande, char **envp);
void ft_outfile_nosplit_append(char **cmd, int *fd, int i, int *j);
void ft_outfile_nosplit(char **cmd, int *fd, int i, int *j);
void ft_outfile_split(char **cmd, int *fd, int *i);
void  ft_process_onlyone_output(int fd_out, char *path_cmd, char **cmd, char **envp);
// ------- export.c -------------
char   **ft_export(char **cmd_test, char **envp, char **nos_variables);
// ------- OLDaaaaa.c -----------
void    ft_printf_all(char **sorted);
void    ft_sort_alpha(char **sorted);
char    **ft_malloc_var(char **original);
char    **ft_malloc_env(char **original);
int ft_nbr_args(char **cmd_test);

#endif