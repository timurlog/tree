/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:59:49 by tilogie           #+#    #+#             */
/*   Updated: 2025/05/07 02:52:02 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static void	g_tree_init(t_tree *g_tree)
{
	g_tree->reverse = 0;
	g_tree->sort = 0;
	g_tree->dir_only = 0;
	g_tree->size = 0;
	g_tree->dir_nbr = 0;
	g_tree->file_nbr = 0;
}

int	main(int argc, char **argv)
{
	t_tree		*g_tree;
	const char	*dir;
	struct stat	st;
	int			i;

	dir = ".";
	i = 1;
	g_tree = malloc(sizeof(t_tree));
	if (!g_tree)
	{
		fprintf(stderr, "Error: Memory allocation failed.\n");
		return (1);
	}
	g_tree_init(g_tree);
	if (argc > 1)
	{
		while (argv[i])
		{
			if (argv[i][0] == '-')
			{
				if (tree_format(argv[i], g_tree) == 1)
				{
					free(g_tree);
					return (1);
				}
			}
			else
				dir = argv[i];
			i++;
		}
	}
	if (stat(dir, &st) == -1 || !S_ISDIR(st.st_mode))
	{
		fprintf(stderr, "Error: Directory '%s' does not exist.\n", dir);
		return (1);
	}
	printf("\033[1;34m%s\033[0m\n", dir);
	generate_tree(dir, "", g_tree);
	printf("\n%d directories, %d files\n", g_tree->dir_nbr, g_tree->file_nbr);
	free(g_tree);
	return (0);
}
