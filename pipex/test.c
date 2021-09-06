#include "pipex.h"

int ft_exit(int i)
{
	if (i == 1)
		exit(1);
	exit(0);
}

void erase_quote(char **av)
{
	for (int i = 1; av[i]; i++)
	{
		for (int k = 0; av[i][k]; k++)
		{
			if (av[i][k] == '\'' || av[i][k] == '\"')
			{
				for (int j = k; av[i][j + 1]; j++)
					av[i][j] = av[i][j + 1];
				av[i][j] = '\n';
			}
		}
	}
}

int main(int ac, char **av, char **env)
{
	char **paths;
	char *infile;
	char *outfile;

	// av all print
	for (int i = 1; i < ac; i++)
		printf("%d: %s\n", i, av[i]);

	// four arguments check
	if (ac != 5)
		ft_exit(1);

	// erase ' or "
	erase_quote(av);

	//infile check
	if (access(av[1], R_OK) != 0)
		ft_exit(1);
	else
		infile = ft_strdup(av[1]);
	printf("infile: %s\n", infile);

	//outfile check
	if (access(av[4], W_OK) != 0)
		open(outfile = ft_strdup(av[4]), O_WRONLY | O_CREAT, 0666);
	else
		outfile = ft_strdup(av[4]);
	printf("outfile: %s\n", outfile);

	//call "path: ...: ...: ..." 
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
