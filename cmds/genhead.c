/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genhead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:47:59 by amenadue          #+#    #+#             */
/*   Updated: 2022/08/30 15:33:54 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libvg/vogship.h"
#include <sys/types.h>
#include <sys/stat.h>

const int	g_cmdindex = 4;

int	str_loc_char(const t_str str, char c)
{
	int	i = 0;
	int sl = ft_strlen(str);

	while (i < sl)
		if (str[i++] == c)
			break ;
	return (i-1);
}

int is_directory(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

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
	buf = (t_str) ft_calloc(setlen, sizeof(char));
	while (i < setlen)
	{
		if (set[i] == ' ' || set[i] == '\0')
		{
			ext = (t_str) ft_calloc(j+2, sizeof(char));
			ft_strlcat(ext, ".", j+2);
			ft_strlcat(ext, buf, j+2);
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
	t_str	tmp;
	t_str	line;
	int		flag;
    size_t	len = 0;

	int proceed;
	t_str start;
	t_str end;

    FILE    *fp;
	int	i;

	i = 1;
	if (c == 1)
	{
		ft_printf("Usage: ");
		vg_cmdhelp(g_cmdindex);
		nl();
	}
	else
	{
		while (i < c)
		{
			tmp = (t_str) ft_calloc(128, sizeof(char));
			ft_strlcat(tmp, "ls ", 128);
			ft_strlcat(tmp, v[i], 128);
			line = vg_run(tmp);
			if (endswith(line, "No such file or directory"))
				ft_printf("Couldn't find %s\n", v[i]);
			else if (is_directory(v[i]))
			{
				line = (char *) ft_calloc(1024, sizeof(char));
				ft_strlcat(line, "cd ", 1024);
				ft_strlcat(line, v[i], 1024);
				ft_strlcat(line, "; ~/.vogship/bin/genhead *; cd ..", 1024);
				system(line);
				free(line);
			}
			else 
			{
				proceed = 0;
				if (hasfileext(v[i], "c cc h hh cpp hpp php"))
				{
					start = ft_strdup("/*");
					end = ft_strdup("*/");
					proceed = 1;
				}
				else if (hasfileext(v[i], "htm html xml"))
				{
					start = ft_strdup("<!--");
					end = ft_strdup("-->");
					proceed = 1;
				}
				else if (hasfileext(v[i], "js"))
				{
					start = ft_strdup("//");
					end = ft_strdup("//");
					proceed = 1;
				}
				else if (hasfileext(v[i], "tex"))
				{
					start = ft_strdup("%");
					end = ft_strdup("%");
					proceed = 1;
				}
				else if (hasfileext(v[i], "ml mli mll mly"))
				{
					start = ft_strdup("(*");
					end = ft_strdup("*)");
					proceed = 1;
				}
				else if (hasfileext(v[i], "vim vimrc"))
				{
					start = ft_strdup("\"");
					end = ft_strdup("\"");
					proceed = 1;
				}
				else if (hasfileext(v[i], "el emacs"))
				{
					start = ft_strdup(";");
					end = ft_strdup(";");
					proceed = 1;
				}
				else if (hasfileext(v[i], "f90 f95 f03 f for"))
				{
					start = ft_strdup("!");
					end = ft_strdup("!");
					proceed = 1;
				}
				else if (hasfileext(v[i], "sh") || !ft_strncmp(v[i], "Makefile", 9))
				{
					start = ft_strdup("#");
					end = ft_strdup("#");
					proceed = 1;
				}

				if (proceed)
				{
					flag = 0;
					fp = fopen(v[i], "r");
					if (!fp)
					{
						fprintf(stderr, "Failed to open %s\n", v[i]);
						return (1);
					}

					while (getline(&line, &len, fp) != EOF)
					{
						line[str_loc_char(line, '\n')] = 0;
						if (startswith(line, start))
						{
							if (endswith(line, end))
							{
								if (regex(line, "By: !"))
									if (regex(line, "! <!"))
										flag++;
								if (regex(line, "Created: !!!!/!!/!! !!:!!:!! by !"))
									flag++;
								if (regex(line, "Updated: !!!!/!!/!! !!:!!:!! by !"))
									flag++;
								if (regex(line, "***************************************************"))
									flag++;
								if (regex(line, "///////////////////////////////////////////////////"))
									flag++;
							}
							else
								break;
						}
						else
							break;
					}
					fclose(fp);

					if (flag < 5)
					{
						vg_stdheader(v[i]);
						ft_printf("%s: Generated!\n", v[i]);
						if (line != NULL)
							free(line);
					}
					else
						ft_printf("%s: Already has :Stdheader!\n", v[i]);
				}
			}
			i++;
		}
	}
	return (0);
}
