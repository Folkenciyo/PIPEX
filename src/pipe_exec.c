/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:30:11 by juguerre          #+#    #+#             */
/*   Updated: 2023/11/29 19:50:50 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex *pipex, char *const *envp)
{
	int	i;

	i = 0;
	close(pipex->p_fd[0]);
	dup2(pipex->p_fd[1], STDOUT_FILENO);
	close(pipex->p_fd[1]);
	dup2(pipex->fd_in, STDIN_FILENO);
	close(pipex->fd_in);
	execve(pipex->cmds_path[0], pipex->cmd[0], envp);
	error_one("Command not found", EXIT_FAILURE);
}

void	parent_process(t_pipex *pipex, char *const *envp)
{
	int		i;
	pid_t	child;

	i = 0;
	child = fork();
	if (child < 0)
		return (error_one("Fork: ", EXIT_FAILURE));
	if (!child)
	{
		close(pipex->p_fd[1]);
		dup2(pipex->p_fd[0], STDIN_FILENO);
		close(pipex->p_fd[0]);
		dup2(pipex->fd_out, STDOUT_FILENO);
		close(pipex->fd_out);
		execve(pipex->cmds_path[1], pipex->cmd[1], envp);
		error_one("Command not found", EXIT_FAILURE);
	}
	else
	{
		close(pipex->p_fd[0]);
		close(pipex->p_fd[1]);
		waitpid(child, NULL, 0);
	}
}

void	ft_exec(t_pipex *pipex, char *const *envp)
{
	pid_t	parent;

	if (pipe(pipex->p_fd) == -1) 
		error_one("Pipe: ", EXIT_FAILURE);
	parent = fork();
	if (parent < 0)
		return (error_one("Fork: ", EXIT_FAILURE));
	if (!parent)
		child_process(pipex, envp);
	else
	{
		waitpid(parent, NULL, 0);
		parent_process(pipex, envp);
	}
}