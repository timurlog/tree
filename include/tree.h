/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:08:09 by tilogie           #+#    #+#             */
/*   Updated: 2025/05/30 15:03:48 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>

typedef struct s_tree
{
	int	reverse;
	int	sort;
	int	dir_only;
	int	size;
	int	dir_nbr;
	int	file_nbr;
}	t_tree;

// Function to generate a tree structure of the directory
void	generate_tree(const char *dir, const char *prefix, t_tree *g_tree);
int		tree_format(const char *str, t_tree *g_tree);
char	*size_cal(const char *path);
char	*folder_size_cal(const char *path);

#endif
