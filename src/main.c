/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:59:49 by tilogie           #+#    #+#             */
/*   Updated: 2025/05/04 01:25:41 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

int	main(int argc, char **argv)
{
	const char	*dir;
	struct stat	st;
	int			i;
	int			j;

	dir = ".";
	i = 1;
	j = 0;
	if (argc > 1)
	{
		while (argv[i])
		{
			if (argv[i][j] == '-')
				tree_format(argv[i]);
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
	generate_tree(dir, "");
	return (0);
}
