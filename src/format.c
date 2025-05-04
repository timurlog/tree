/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 01:25:59 by tilogie           #+#    #+#             */
/*   Updated: 2025/05/04 02:06:52 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	tree_format(const char *str)
{
	char *user;

	user = getenv("USER");
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
		if (user)
		{
			char command[256];
			snprintf(command, sizeof(command), "bash /home/%s/tree/bin/update.sh", user);
			if (system(command) == -1)
			{
				fprintf(stderr, "Error: Failed to execute update script.\n");
				printf("Use this: bash -c \"$(curl -fsSL https://raw.github.com/timurlog/tree/main/bin/update.sh)\"\n");
				exit(1);
			}
		}
		else
		{
			fprintf(stderr, "Error: Unable to determine the user.\n");
		}
		exit(1);
	}
	else
	{
		fprintf(stderr, "Error: Invalid option '%s'.\n", str);
		fprintf(stderr, "Use '-help' for usage information.\n");
		exit(1);
	}
}