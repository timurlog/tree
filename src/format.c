/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 01:25:59 by tilogie           #+#    #+#             */
/*   Updated: 2025/05/04 01:59:08 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	tree_format(const char *str)
{
	if (!strcmp(str, "-version"))
	{
		printf("tree version 0.1.1\n");
		exit(1);
	}
	else if (!strcmp(str, "-help") || !strcmp(str, "-h"))
	{
		printf("Usage: tree [options] [directory]\n");
		printf("Options:\n");
		printf("  -r : Reverse order\n");
		printf("  -t : Sort by modification time\n");
		printf("  -d : Show directories only\n");
		printf("  -s : Show size\n");
		printf("  -h : Show help\n");
		exit(1);
	}
	else if (!strcmp(str, "-update"))
	{
		system("bash bin/update.sh");
		exit(1);
	}
	else
	{
		fprintf(stderr, "Error: Invalid option '%s'.\n", str);
		fprintf(stderr, "Use '-help' for usage information.\n");
		exit(1);
	}
}