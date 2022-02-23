/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vg_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:35:19 by coffee            #+#    #+#             */
/*   Updated: 2022/02/23 14:43:32 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vogship.h"

int	startswith(const t_str s, const t_str w)
{
	int	sl;
	int	wl;
	int	i;

	sl = strlen(s);
	wl = strlen(w);
	if (sl >= wl)
	{
		i = 0;
		while (i < wl)
		{
			if (s[i] != w[i])
			{
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

int	endswith(const t_str s, const t_str w)
{
	int	sl;
	int	wl;
	int	i;

	sl = strlen(s) - 1;
	wl = strlen(w) - 1;
	if (sl >= wl)
	{
		i = 0;
		while (i < wl)
		{
			if (s[sl - i] != w[wl - i])
			{
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

int	contains(t_str s, char l)
{
	int	sl;
	int	i;

	sl = strlen(s);
	i = 0;
	while (i < sl)
	{
		if (s[i] == l)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	nl(void)
{
	printf("\n");
}

t_str	vg_run(const t_str cmd)
{
	FILE	*fp;
	t_str	line;
	int		i;

	line = (char *) malloc(512 * sizeof(char));
	fp = popen(cmd, "r");
	if (fp == NULL)
	{
		printf("Failed to run command: %s\n", cmd);
		return ("-1");
	}
	while (fgets(line, 512, fp) != NULL)
		;
	return (line);
}

void	vg_runp(const t_str cmd)
{
	FILE	*fp;
	t_str	line;
	int		i;

	line = (char *) malloc(512 * sizeof(char));
	fp = popen(cmd, "r");
	if (fp == NULL)
	{
		printf("Failed to run command: %s\n", cmd);
		return ;
	}
	while (fgets(line, 512, fp) != NULL)
		printf("%s", line);
}
