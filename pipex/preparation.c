#include "pipex.h"

void erase_quote(char **av)
{
	int i;
	int j;
	int k;

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

void check_infile_outfile(char **av, t_var *var)
{
	int tmp;

	var->infile = ft_strdup(av[1]);
	if (access(var->infile, R_OK) < 0)
	{
		write(STDERR_FILENO, "bash: ", 7);
		perror(var->infile);
		ft_exit(1, var);
	}
	var->infd = open(var->infile, O_RDONLY);
	if (var->infd < 0)
	{
		write(STDERR_FILENO, "bash: ", 7);
		perror(var->infile);
		ft_exit(4, var);
	}
	var->outfile = ft_strdup(av[4]);
	var->outfd = open(var->outfile, O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR);
	if (var->outfd < 0)
	{
		write(STDERR_FILENO, "bash: ", 7);
		perror(var->outfile);
		ft_exit(1, var);
	}
}

void make_paths(char **env, t_var *var)
{
	int i;
	int tmp;
	char *tmpenv;

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

void find_cmd(t_var *var, int i, char **cmd, int *okay)
{
	char *tmp;

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
		free(*cmd);
		*cmd = tmp;
	}
}