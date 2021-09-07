#ifndef PIPEX_H
#define PIPEX_H

# include <unistd.h>   //access unlink close read fork pipe dup dup2 execve
# include <stdlib.h>   //malloc free exit
# include <fcntl.h>    // open write
# include <sys/wait.h> // wait waitpid
# include <stdio.h>    // perror
# include <string.h>   // strerror
# include "libft.h"

typedef struct s_var
{
	char **paths;
	char **cmd1;
	char **cmd2;
	char *in;
	char *out;
} t_var;

void check_infile_outfile(char **av, t_var *var);
void erase_quote(char **av);
int ft_exit(int i);



#endif