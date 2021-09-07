#include "pipex.h"

int	ft_exit(int i)
{
	if (i == 1)
		exit(1);
	exit(0);
}

void	erase_quote(char **av)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j] == '\'' || av[i][j] == '\"')
			{
				k = j;
				while (av[i][k + 1])
				{
					av[i][k] = av[i][k + 1];
					k++;
				}
				av[i][k] = '\0';
				j--;
			}
		}
	}
}

void	check_infile_outfile(char **av, t_var *var)
{
	var->in = ft_strdup(av[1]);
	if (access(av[1], R_OK) != 0)
		ft_exit(1);
	printf("var->in: %s\n", var->in);
	var->out = ft_strdup(av[4]);
	if (access(var->out, W_OK) != 0)
		open(var->out, O_WRONLY | O_CREAT, 0666);
	printf("var->out: %s\n", var->out);
}

void	make_paths(char **env, t_var *var)
{
	int		i;
	int		tmp;
	char	*tmpenv;

	i = -1;
	while (env[++i])
	{
		tmp = ft_strncmp(ft_substr(env[i], 0, 5), "PATH=", 5);
		if (tmp == 0)
		{
			tmpenv = ft_substr(env[i], 5, ft_strlen(env[i]) - 5);
			var->paths = ft_split(tmpenv, ':');
			break ;
		}
	}
}

void	which_cmd(char *path, char **cmd, int *okay)
{
	char	*tmp;
	int		len;

	tmp = ft_strdup(path);
	ft_strlcat(tmp, "/", ft_strlen(tmp) + 2);
	len = ft_strlen(tmp) + ft_strlen(cmd[0]) + 1;
	ft_strlcat(tmp, cmd[0], len);
	if (access(tmp, X_OK) == 0)
		(*okay)++;
}

void	check_cmd_in_paths(t_var *var)
{
	int	okay;
	int	i;
	int	len;

	okay = 0;
	i = -1;
	while (var->paths[++i])
	{
		which_cmd(var->paths[i], var->cmd1, &okay);
		which_cmd(var->paths[i], var->cmd2, &okay);
		if (okay == 2)
			break ;
	}
	if (okay != 2)
		ft_exit(1);
}

int	main(int ac, char **av, char **env)
{
	t_var	var;

	if (ac != 5)
		ft_exit(1);
	erase_quote(av);
	check_infile_outfile(av, &var);
	var.cmd1 = ft_split(av[2], ' ');
	var.cmd2 = ft_split(av[3], ' ');
	make_paths(env, &var);
	check_cmd_in_paths(&var);
	printf("cmd1: %s\n", var.cmd1[0]);
	printf("cmd2: %s\n", var.cmd2[0]);
	printf("in: %s\n", var.in);
	printf("out: %s\n", var.out);
	ft_exit(0);
}
