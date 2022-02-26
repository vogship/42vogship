/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genhead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:47:59 by amenadue          #+#    #+#             */
/*   Updated: 2022/02/26 11:48:40 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libvg/vogship.h"

const int	g_cmdindex = 4;

int hasfileext(t_str file, t_str set)
{
	int		i;
	int		j;
	int		setlen;
	t_str	buf;
	t_str	ext;

	i = 0;
	j = 0;
	setlen = ft_strlen(set);
	buf = (t_str) malloc(setlen * sizeof(char));
	while (i < setlen)
	{
		if (set[i] == ' ' || set[i] == '\0')
		{
			ext = ft_strdup(".");
			ft_strlcat(ext, buf, j);
			if (endswith(file, ext))
				return (1);
			ft_bzero(buf, setlen);
			j = 0;
		}
		else
		{
			buf[j] = set[i];
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int c, t_str *v)
{
	t_str	line;
	int		flag;
    size_t	len = 0;
    ssize_t	read;

    FILE    *fp;
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
			line = strdup("ls ");
			ft_strlcat(line, v[i], 128);
			line = vg_run(line);
			if (endswith(line, "No such file or directory"))
			{
				printf("Couldn't find %s\n", v[i]);
			}
			else if (!strcmp(line, v[i]))
			{
				line = strdup("~/.vogship/bin/genhead ");
				ft_strlcat(line, v[i], 128);
				ft_strlcat(line, "/*", 128);
				vg_runp(line);
			}
			else 
			{
				if (hasfileext(v[i], "c cc h hh cpp hpp php")) {
					flag = 0;
					fp = fopen(v[i], "r");
					if (!fp) {
						fprintf(stderr, "Failed to open %s\n", v[i]);
						return (1);
					}

					while (getline(&line, &len, fp) != -1) {
						line[strcspn(line, "\n")] = 0;
						if (startswith(line, "/*")) {
							if (endswith(line, "*/")) {
								if (regex(line, "By: !"))
									if (regex(line, "! <!"))
										flag++;
								if (regex(line, "Created: !!!!/!!/!! !!:!!:!! by !"))
									flag++;
								if (regex(line, "Updated: !!!!/!!/!! !!:!!:!! by !"))
									flag++;
								if (regex(line, "**************************************************************************"))
									flag++;
							} else {
								break;
							}
						} else {
							break;
						}
					}
					fclose(fp);

					if (flag < 5) {
						line = ft_strdup("vim -c \"Stdheader\" -c \"wq\" ");
						ft_strlcat(line, v[i], ft_strlen(v[i]) + strlen(line));
						system(line);
						free(line);
						printf("%s: Generated!\n", v[i]);
					} else {
						printf("%s: Already has :Stdheader!\n", v[i]);
					}
				}
			}
			i++;
		}
	}
	return (0);
}
