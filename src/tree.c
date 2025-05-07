/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:00:19 by tilogie           #+#    #+#             */
/*   Updated: 2025/05/07 03:10:01 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static int	is_valid_entry(const char *name, int only_dirs, struct dirent *entry)
{
	if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
		return (0);
	if (only_dirs && entry->d_type != DT_DIR)
		return (0);
	return (1);
}

static int	has_next_valid_entry(struct dirent **namelist, int start, int n, int only_dirs)
{
	for (int j = start; j < n; j++)
	{
		if (is_valid_entry(namelist[j]->d_name, only_dirs, namelist[j]))
			return (1);
	}
	return (0);
}

static void	process_entry(const char *dir, const char *prefix, t_tree *g_tree, struct dirent *entry, int is_last)
{
	char	path[1024];
	char	new_prefix[1024];

	snprintf(path, sizeof(path), "%s/%s", dir, entry->d_name);
	if (entry->d_type == DT_DIR)
	{
		printf("%s%s── \033[1;34m%s\033[0m\n", prefix, is_last ? "└" : "├", entry->d_name);
		g_tree->dir_nbr += 1;
		if (strcmp(entry->d_name, ".git") != 0)
		{
			snprintf(new_prefix, sizeof(new_prefix), "%s%s   ", prefix, is_last ? " " : "│");
			generate_tree(path, new_prefix, g_tree);
		}
	}
	else if (!g_tree->dir_only && entry->d_type == DT_REG)
	{
		printf("%s%s── %s\n", prefix, is_last ? "└" : "├", entry->d_name);
		g_tree->file_nbr += 1;
	}
}

void	generate_tree(const char *dir, const char *prefix, t_tree *g_tree)
{
	struct dirent	**namelist;
	int				is_last;
	int				n;

	n = scandir(dir, &namelist, NULL, alphasort);
	if (n < 0)
	{
		perror("scandir");
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		if (!is_valid_entry(namelist[i]->d_name, g_tree->dir_only, namelist[i]))
		{
			free(namelist[i]);
			continue ;
		}
		is_last = !has_next_valid_entry(namelist, i + 1, n, g_tree->dir_only);
		process_entry(dir, prefix, g_tree, namelist[i], is_last);
		free(namelist[i]);
	}
	free(namelist);
}
