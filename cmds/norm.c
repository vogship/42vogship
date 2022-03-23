/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:47:59 by amenadue          #+#    #+#             */
/*   Updated: 2022/03/24 07:55:16 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libvg/vogship.h"
#include <sys/types.h>
#include <sys/stat.h>

const int	g_cmdindex = 7;

int is_directory(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
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
			else if (is_directory(v[i]))
			{
				line = ft_strdup("~/.vogship/bin/norm ");
				ft_strlcat(line, v[i], 128);
				ft_strlcat(line, "/*", 128);
				vg_runp(line);
			}
			else
			{
				if (endswith(v[i], ".c"))
				{
					tmp = (t_str) malloc(128 * sizeof(char));
					ft_strlcat(tmp, "norminette -R CheckForbiddenSourceHeader ", 128);
					ft_strlcat(tmp, v[i], 128);
					system(tmp);
				}
				if (endswith(v[i], ".h"))
				{
					tmp = (t_str) malloc(128 * sizeof(char));
					ft_strlcat(tmp, "norminette -R CheckDefine ", 128);
					ft_strlcat(tmp, v[i], 128);
					system(tmp);
				}
			}
			i++;
		}

	}
	return (0);
}
