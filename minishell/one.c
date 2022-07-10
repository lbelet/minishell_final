#include "minishell.h"

void  ft_process_onlyone(char *path_cmd, char **cmd, char **envp)
{
  execve(path_cmd, cmd, envp);
}

int ft_process_one_classic(char **cmd, char **envp)
{
	int pid;
	char *path_cmd;

	path_cmd = ft_path(cmd[0]);
	if (ft_error(path_cmd, cmd) == 0)
		return (0);
   	pid = fork();
    if (pid < 0)
       	return (0);
   	if (pid == 0)
        ft_process_onlyone(path_cmd, cmd, envp);
   	waitpid(pid, NULL, 0);
	free(path_cmd);
	return (0);
}

void ft_one(char *str, char **envp)
{
	char **cmd;
	int *fd;
	char **commande;
	int i;

	i = 0;
	fd = malloc(2 * sizeof(int));
	fd[0] = 0;
	fd[1] = 0;
    cmd = ft_split_modif(str, ' ', ft_code_char(str));
//	ft_execute_inbuilt(cmd, envp, &args_in);
//	if (ft_check_builtins(cmd) == 0)
//	{
		commande = ft_malloc_tab(cmd);
		ft_check_redir(fd, cmd, commande);
//		if (fd[0] > 0 && fd[1] > 0)
//			ft_exec_in_out(fd, commande, envp);
//		else if (fd[0] > 0 && fd[1] == 0)
//			ft_exec_in(fd[0], commande, envp);
//		else if (fd[0] == 0 && fd[1] > 0)
//			ft_exec_out(fd[1], commande, envp);
		if (fd[0] == 0 && fd[1] == 0)
			ft_process_one_classic(commande, envp);
		ft_free_tab_simple(cmd);
    //    ft_free_tab_simple(commande);
//		free(fd);
//	}
}