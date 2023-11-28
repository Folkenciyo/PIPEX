/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:32:37 by juguerre          #+#    #+#             */
/*   Updated: 2023/11/22 13:48:16by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

void	add_cmd(t_pipex *pipex, char **argv)
{
	pipex->cmd = malloc(sizeof(char **) * 3);
	if (!pipex->cmd)
		error_one("Allocating mem to 'pipex->cmd'", EXIT_SUCCESS);
	pipex->cmd[0] = ft_split(argv[2], ' ');
	pipex->cmd[1] = ft_split(argv[3], ' ');
	pipex->cmd[2] = NULL;
}

void	ft_check_args(t_pipex *pipex, char **argv)
{
	if (argv[1])
		pipex->infile = argv[1];
	else
		error_two("File not found", pipex->infile, EXIT_FAILURE);
	if (argv[4])
		pipex->outfile = argv[4];
	else
		error_two("File not found", pipex->outfile, EXIT_FAILURE);
	if (argv[2] && argv[3])
		add_cmd(pipex, argv);
	else
		error_one("Command error\n", EXIT_SUCCESS);
}

void	ft_parse_cmds(t_pipex *pipex, char **envp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	// si no hay path, error FALTA
	while (ft_strncmp(envp[i], "PATH=", 5) && envp[i])
		i++;
	pipex->path = ft_strdup(&envp[i][5]);
	pipex->cmd_paths = ft_split(pipex->path, ':');
	free(pipex->path);
	pipex->path = NULL;
	i = 0;
	init_chosen_path(pipex);
	while (j < 2)
	{
		while (pipex->cmd_paths[i])
		{
			pipex->chosen_path[j][i] = ft_strjoin(pipex->cmd_paths[i], "/");
			pipex->chosen_path[j][i] = ft_strjoin_p(pipex->chosen_path[j][i],
					pipex->cmd[j][0]);	
			i++;
		}
		pipex->chosen_path[j][i] = NULL;
		i = 0;
		j++;
	}
	pipex->chosen_path[j] = NULL;
}

void	ft_leaks(void)
{
	system("leaks -q pipex");
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	atexit(ft_leaks);
	pipex = NULL;
	if (argc == 5)
	{
		pipex = init_pipex(pipex);
		ft_check_args(pipex, argv);
		add_cmd(pipex, argv);
		ft_parse_cmds(pipex, envp);
		ft_cleanup(pipex);
	}
	return (0);
}

/* esquema de main
main()
{
	ft_init_pipex() *****
	ft_check_args() *****
	ft_parse_cmds() *****
	ft_add_cmd() *****
	while (cmds)
		ft_exec()
	ft_cleanup()
}
 */