#ifndef PIPEX_H
# define PIPEX_H

# define READ 0
# define WRITE 1

# include <unistd.h>   //access unlink close read fork pipe dup dup2 execve
# include <stdlib.h>   //malloc free exit
# include <fcntl.h>    // open write
# include <sys/wait.h> // wait waitpid
# include <stdio.h>    // perror
# include <string.h>   // strerror
# include "libft.h"

typedef struct s_var
{
	char *in;
	char *out;
	char **paths;
	char **cmd1;
	char **cmd2;
	int fdinfile;
	int fdoutfile;
	int pp[2];
} t_var;

void check_infile_outfile(char **av, t_var *var);
void erase_quote(char **av);
void	make_paths(char **env, t_var *var);
void	find_cmd(t_var *var, int i, char **cmd, int *okay);
void	check_cmd_in_paths(t_var *var);


int ft_exit(int i);


#endif