/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:00:19 by tilogie           #+#    #+#             */
/*   Updated: 2025/05/06 19:16:41 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	generate_tree(const char *dir, const char *prefix, t_tree *g_tree)
{
	struct dirent	**namelist;
	struct stat		st;
	const char		*name;
	char			path[1024];
	char			new_prefix[1024];
	int				is_last;
	int				n;

	n = scandir(dir, &namelist, NULL, alphasort);
	if (n < 0)
	{
		perror("scandir");
		return ;
	}
	if (n == 2)
	{
		printf("%s└── \033[1;93m%s\033[0m\n", prefix, "(empty)");
		free(namelist);
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		name = namelist[i]->d_name;
		if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0 || strcmp(name, ".git") == 0)
		{
			free(namelist[i]);
			continue ;
		}
		snprintf(path, sizeof(path), "%s/%s", dir, name);
		if (stat(path, &st) == -1)
		{
			perror("stat");
			free(namelist[i]);
			continue ;
		}
		is_last = (i == n - 1);
		if (S_ISDIR(st.st_mode))
		{
			printf("%s%s── \033[1;34m%s\033[0m\n", prefix, is_last ? "└" : "├", name);
			g_tree->dir_nbr += 1;
			snprintf(new_prefix, sizeof(new_prefix), "%s%s   ", prefix, is_last ? " " : "│");
			generate_tree(path, new_prefix, g_tree);
		}
		else
		{
			printf("%s%s── %s\n", prefix, is_last ? "└" : "├", name);
			g_tree->file_nbr += 1;
		}
		free(namelist[i]);
	}
	free(namelist);
}
