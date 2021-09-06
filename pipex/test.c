#include "pipex.h"

int ft_exit(int i)
{
	if (i == 1)
		exit(1);
	exit(0);
}

int main(int ac, char **av, char **env)
{
	char **paths;

	for (int i = 1; i < ac; i++)
		printf("%d: %s\n", i, av[i]);
	if (ac != 5)
		ft_exit(1);
	for (int i = 0; env[i] != 0; i++)
	{
		if (ft_strncmp(ft_substr(env[i], 0, 4), "PATH", 4) == 0)
		{
			paths = ft_split(ft_substr(env[i], 5, ft_strlen(env[i]) - 5), ':');
			break;
		}
	}
	for (int i = 0; paths[i] != 0; i++)
		printf("%s\n", paths[i]);
	ft_exit(0);
}
