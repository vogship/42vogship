/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:47:59 by amenadue          #+#    #+#             */
/*   Updated: 2022/02/28 18:14:43 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libvg/vogship.h"
#include <sys/types.h>
#include <sys/stat.h>

const int	g_cmdindex = 7;

int is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

int	main(int c, t_str *v)
{
	t_str tmp;
	t_str line;
	int	i;

	i = 1;
	if (c == 1)
	{
		printf("Usage: ");
		vg_cmdhelp(g_cmdindex);
		nl();
	}
	else
	{
		while (i < c)
		{
			tmp = ft_strdup("ls ");
			ft_strlcat(tmp, v[i], 128);
			line = vg_run(tmp);
			if (endswith(line, "No such file or directory"))
			{
				printf("Couldn't find %s\n", v[i]);
			}
			else if (!is_regular_file(v[i]))
			{
				line = strdup("~/.vogship/bin/norm ");
				ft_strlcat(line, v[i], 128);
				ft_strlcat(line, "/*", 128);
				vg_runp(line);
			}
			else
			{
				if (endswith(v[i], ".c"))
				{
					tmp = ft_strdup("norminette -R CheckForbiddenSourceHeader ");
					ft_strlcat(tmp, v[i], 128);
					vg_runp(tmp);
				}
				if (endswith(v[i], ".h"))
				{
					tmp = ft_strdup("norminette -R CheckDefine ");
					ft_strlcat(tmp, v[i], 128);
					vg_runp(tmp);
				}
			}
			i++;
		}

	}
	return (0);
}
