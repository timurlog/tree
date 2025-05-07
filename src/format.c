/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 01:25:59 by tilogie           #+#    #+#             */
/*   Updated: 2025/05/07 15:11:57 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static int	print_version(t_tree *g_tree)
{
	printf("tree version 0.1.3\n");
	free(g_tree);
	exit (0);
}

static int	print_help(t_tree *g_tree)
{
	printf("Usage: tree [options] [directory]\n");
	printf("Options:\n");
	printf("  --version	--  Show version information\n");
	printf("  --update	--  Update the program\n");
	printf("  -r		--  Sort in reversed order\n");
	printf("  -t		--  Sort output by modification time\n");
	printf("  -d		--  List directories only\n");
	printf("  -s		--  Print size of each file in bytes\n");
	free(g_tree);
	exit (0);
}

static int	print_update(void)
{
	char	*user;
	char	command[256];

	user = getenv("USER");
	if (user)
	{
		snprintf(command, sizeof(command), "bash /home/%s/tree/bin/update.sh", user);
		if (system(command) == -1)
		{
			fprintf(stderr, "Error: Failed to execute update script.\n");
			printf("Use this: bash -c \"$(curl -fsSL https://raw.github.com/timurlog/tree/main/bin/update.sh)\"\n");
			return (1);
		}
	}
	else
		fprintf(stderr, "Error: Unable to determine the user.\n");
	return (1);
}

static int	print_error(const char *str)
{
	fprintf(stderr, "Error: Invalid option '%s'.\n", str);
	fprintf(stderr, "Use '--help' for usage information.\n");
	return (1);
}

int	tree_format(const char *str, t_tree *g_tree)
{
	int	i;

	i = 0;
	if (!strcmp(str, "--version"))
		i = print_version(g_tree);
	else if (!strcmp(str, "--help") || !strcmp(str, "-h"))
		i = print_help(g_tree);
	else if (!strcmp(str, "--update"))
		i = print_update();
	else if (!strcmp(str, "-r"))
		g_tree->reverse = 1;
	else if (!strcmp(str, "-t"))
		g_tree->sort = 1;
	else if (!strcmp(str, "-d"))
		g_tree->dir_only = 1;
	else if (!strcmp(str, "-s"))
		g_tree->size = 1;
	else
		i = print_error(str);
	return (i);
}
