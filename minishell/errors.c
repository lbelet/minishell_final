#include "minishell.h"

int	ft_error(char *path_cmd, char **cmd_infile)
{
	if (path_cmd[0] == 'E')
	{
		printf("Command %s not found\n", cmd_infile[0]);
		ft_free_tab_simple(cmd_infile);
		return (0);
	}
	else
		return (1);
}

void ft_error_fd(int fd, char *infile)
{
	if (fd < 0)
		printf("Probleme d'access au fichier: %s\n", infile);
}