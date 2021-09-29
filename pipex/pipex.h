#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>   //access unlink close read fork pipe dup dup2 execve
# include <stdlib.h>   //malloc free exit
# include <fcntl.h>    // open write
# include <sys/wait.h> // wait waitpid
# include <stdio.h>    // perror
# include <string.h>   // strerror
# include <errno.h>
# include "libft.h"

typedef struct s_var
{
	char *infile;
	char *outfile;
	char **paths;
	char **cmd1;
	char **cmd2;
	int infd;
	int outfd;
	int pp[2];
} t_var;

void	check_infile_outfile(char **av, t_var *var);
void	erase_quote(char **av);
void	make_paths(char **env, t_var *var);
void	find_cmd(t_var *var, int i, char **cmd, int *okay);
void	prepare_everything(t_var *var, char **av, char **env);

void	parent_process(t_var *var, char **env);
void	child_process_1(t_var *var, char **env);
void	child_process_2(t_var *var, char **env);

int		ft_exit(int i, t_var *var);
void	default_var(t_var *var);

#endif