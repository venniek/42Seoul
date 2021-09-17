#include "pipex.h"

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
	int tmp;

	var->in = ft_strdup(av[1]);
	if (access(av[1], R_OK) != 0)
		ft_exit(1);
	var->fdinfile = open(var->in, O_RDWR);
	if (tmp < 0)
		ft_exit(1);
	var->out = ft_strdup(av[4]);
var->fdoutfile = open(var->out, O_RDWR | O_CREAT, 0666);

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
			break;
		}
	}
}

void	find_cmd(t_var *var, int i, char **cmd, int *okay)
{
	char	*tmp;

	if (access(*cmd, X_OK) == 0)
	{
		(*okay)++;
		return;
	}
	tmp = ft_strdup(var->paths[i]);
	tmp = ft_strjoin(tmp, "/");
	tmp = ft_strjoin(tmp, *cmd);
	if (access(tmp, X_OK) == 0)
	{
		(*okay)++;
		*cmd = tmp;
	}
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
		find_cmd(var, i, &var->cmd1[0], &okay);
		if (okay == 1)
			break;
	}
	i = -1;
	while (var->paths[++i])
	{
		find_cmd(var, i, &var->cmd2[0], &okay);
		if (okay == 2)
			break;
	}
	if (okay != 2)
		ft_exit(1);
}
