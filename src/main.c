/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:59:49 by tilogie           #+#    #+#             */
/*   Updated: 2025/05/04 01:05:04 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

int	main(int argc, char **argv)
{
	const char	*dir;
	struct stat	st;

	dir = ".";
	if (argc > 1)
		dir = argv[1];
	if (stat(dir, &st) == -1 || !S_ISDIR(st.st_mode))
	{
		fprintf(stderr, "Error: Directory '%s' does not exist.\n", dir);
		return (1);
	}
	printf("\033[1;34m%s\033[0m\n", dir);
	generate_tree(dir, "");
	return (0);
}
