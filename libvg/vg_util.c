/* ========================================================================== */
/*                                                                            */
/*                                                             /   /   \      */
/*   Made By IsCoffeeTho (Aaron Menadue)                     /    |      \    */
/*                                                          |     |       |   */
/*   vg_util.c                                              |      \      |   */
/*                                                          |       |     |   */
/*   Last Edited: 08:24AM 17/08/2023                         \      |    /    */
/*                                                             \   /   /      */
/*                                                                            */
/* ========================================================================== */

#include "vogship.h"

int	startswith(const t_str s, const t_str w)
{
	int	sl;
	int	wl;
	int	i;

	sl = ft_strlen(s);
	wl = ft_strlen(w);
	if (sl >= wl)
	{
		i = 0;
		while (i < wl)
		{
			if (s[i] != w[i])
				return (0);
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

	sl = ft_strlen(s);
	wl = ft_strlen(w);
	if (sl >= wl)
	{
		i = 0;
		while (i < wl + 1)
		{
			if (s[sl - i] != w[wl - i])
				return (0);
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

	sl = ft_strlen(s);
	i = 0;
	while (i < sl)
	{
		if (s[i] == l)
			return (1);
		i++;
	}
	return (0);
}

void	nl(void)
{
	ft_printf("\n");
}

t_str	vg_run(const t_str cmd)
{
	FILE	*fp;
	t_str	line;

	line = (char *) malloc(512 * sizeof(char));
	fp = popen(cmd, "r");
	if (fp == NULL)
	{
		ft_printf("Failed to run command: %s\n", cmd);
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

	line = (char *) malloc(512 * sizeof(char));
	fp = popen(cmd, "r");
	if (fp == NULL)
	{
		ft_printf("Failed to run command: %s\n", cmd);
		return ;
	}
	while (fgets(line, 512, fp) != NULL)
		ft_printf("%s", line);
	free(line);
}
