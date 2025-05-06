/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 01:25:59 by tilogie           #+#    #+#             */
/*   Updated: 2025/05/06 13:53:25 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	print_version(void)
{
	printf("tree version 0.1.2\n");
	exit(1);
}

void	print_help(void)
{
	printf("Usage: tree [options]... [directory]\n");
	printf("Options:\n");
	printf("  -r : Reverse order\n");
	printf("  -t : Sort by modification time\n");
	printf("  -d : Show directories only\n");
	printf("  -s : Show size\n");
	printf("  -h : Show help\n");
	exit(1);
}

void	print_update(void)
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
			exit(1);
		}
	}
	else
		fprintf(stderr, "Error: Unable to determine the user.\n");
	exit(1);
}

void	print_error(const char *str)
{
	fprintf(stderr, "Error: Invalid option '%s'.\n", str);
	fprintf(stderr, "Use '--help' for usage information.\n");
	exit(1);
}

void	tree_format(const char *str)
{
	if (!strcmp(str, "--version"))
		print_version();
	else if (!strcmp(str, "--help") || !strcmp(str, "-h"))
		print_help();
	else if (!strcmp(str, "--update"))
		print_update();
	else
		print_error(str);
}
