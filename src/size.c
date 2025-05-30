/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:01:55 by tilogie           #+#    #+#             */
/*   Updated: 2025/05/30 23:10:04 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static size_t	folder_size_sum(const char *path)
{
	struct dirent	*entry;
	DIR				*dir;
	struct stat		st;
	size_t			total_size;
	char			filepath[1024];

	dir = opendir(path);
	total_size = 0;
	if (!dir)
		return (0);
	while ((entry = readdir(dir)) != NULL)
	{
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
			continue ;
		snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);
		if (stat(filepath, &st) == 0)
		{
			if (S_ISREG(st.st_mode))
				total_size += st.st_size;
			else if (S_ISDIR(st.st_mode))
				total_size += folder_size_sum(filepath);
		}
	}
	closedir(dir);
	return (total_size);
}

char	*folder_size_cal(const char *path)
{
	static char	buf[32];
	size_t		total_size;
	double		size_kib;

	total_size = folder_size_sum(path);
	size_kib = total_size / 1024.0;
	if (size_kib < 1024.0)
		snprintf(buf, sizeof(buf), "\033[0;96m[%-6.1fKiB]\033[0;39m ", size_kib);
	else
		snprintf(buf, sizeof(buf), "\033[0;96m[%-6.2fMiB]\033[0;39m ", size_kib / 1024.0);
	return (buf);
}

char	*size_cal(const char *path)
{
	static char	buf[32];
	struct stat	st;
	double		size_kib;

	if (stat(path, &st) == 0)
	{
		size_kib = st.st_size / 1024.0;
		if (size_kib < 1024.0)
			snprintf(buf, sizeof(buf), "\033[0;96m[%-6.1fKiB]\033[0;39m ", size_kib);
		else
			snprintf(buf, sizeof(buf), "\033[0;96m[%-6.2fMiB]\033[0;39m ", size_kib / 1024.0);
		return (buf);
	}
	return ("");
}
