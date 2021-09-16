#include "pipex.h"

void child_process(t_var *var, char **env)
{
	close(var->fd[READ]);
	execve(var->in, var->cmd1, env);
	dup2()
	write(var->fd[WRITE], );
}

void parent_process(t_var *var, char **env)
{
	wait(NULL);
	close(var->fd[WRITE]);
	read(fd[READ], )

}