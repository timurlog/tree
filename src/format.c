/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 01:25:59 by tilogie           #+#    #+#             */
/*   Updated: 2025/05/04 01:28:20 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	tree_format(const char *str)
{
	int	i;

	i = 1;
	if (str == "-version")
	{
		printf("Tree version 0.1.0\n");
		exit(0);
	}
	while (str[i])
	{
		// if (str[i] == 'a')
		// 	g_format.a = 1;
		// else if (str[i] == 'l')
		// 	g_format.l = 1;
		// else if (str[i] == 'r')
		// 	g_format.r = 1;
		// else if (str[i] == 't')
		// 	g_format.t = 1;
		// else if (str[i] == 'R')
		// 	g_format.R = 1;
		// else if (str[i] == 'd')
		// 	g_format.d = 1;
		// else if (str[i] == 'h')
		// 	g_format.h = 1;
		// i++;
	}
}