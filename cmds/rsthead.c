/* ========================================================================== */
/*                                                                            */
/*                                                             /   /   \      */
/*   Made By IsCoffeeTho (Aaron Menadue)                     /    |      \    */
/*                                                          |     |       |   */
/*   rsthead.c                                              |      \      |   */
/*                                                          |       |     |   */
/*   Last Edited: 08:29AM 17/08/2023                         \      |    /    */
/*                                                             \   /   /      */
/*                                                                            */
/* ========================================================================== */

#include "../libvg/vogship.h"
#include <sys/types.h>
#include <sys/stat.h>

const int	g_cmdindex = 5;

int	str_loc_char(const t_str str, char c)
{
	int	i = 0;
	int sl = ft_strlen(str);

	while (i < sl)
		if (str[i++] == c)
			break ;
	return (i-1);
}

int is_directory(const t_str path)
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
	buf = (t_str) malloc(setlen * sizeof(char));
	while (i < setlen)
	{
		if (set[i] == ' ')
		{
			ext = (t_str) malloc((j+2) * sizeof(char));
			ft_strlcat(ext, ".", 1);
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
	t_str	tmp;
	t_str	line;
	int		flag;
	int		start_writing;

	int		proceed;
	t_str	start;
	t_str	end;

    FILE    *fp;
	FILE	*nfp;
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
			tmp = (t_str) ft_calloc(128 , sizeof(char));
			ft_strlcat(tmp, "ls ", 128);
			ft_strlcat(tmp, v[i], 128);
			line = vg_run(tmp);
			if (endswith(line, "No such file or directory"))
			{
				ft_printf("Couldn't find %s\n", v[i]);
			}
			else if (is_directory(v[i]))
			{
				line = (t_str) malloc(128 * sizeof(char));
				ft_strlcat(line, "~/.vogship/bin/rsthead ", 128);
				ft_strlcat(line, v[i], 128);
				ft_strlcat(line, "/*", 128);
				vg_runp(line);
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
				else if (hasfileext(v[i], "sh") || endswith(v[i], "Makefile"))
				{
					start = ft_strdup("#");
					end = ft_strdup("#");
					proceed = 1;
				}
				else
				{
					
				}

				if (proceed)
				{
					flag = 0;
					start_writing = 0;
					fp = fopen(v[i], "r");
					nfp = fopen("vgrmheader", "w");
					if (!fp)
					{
						fprintf(stderr, "Failed to open %s\n", v[i]);
						return (1);
					}
					if (!nfp)
					{
						fprintf(stderr, "Failed to open %s\n", v[i]);
						return (1);
					}
					
					line = (t_str) malloc(512 * sizeof(char));
					while (fgets(line, 512, fp) != NULL)
					{
						line[str_loc_char(line, '\n')] = 0;
						if (start_writing)
						{
							fprintf(nfp, "%s\n", line);
						}
						else 
						{
							if (flag >= 11)
							{
								if (!ft_strncmp(line, "", 1)) {
									start_writing = 1;
								}
							}
							if (startswith(line, start) && endswith(line, end))
							{
								flag++;
							}
						}
					}
					fclose(fp);
					fclose(nfp);
					if (flag >= 11)
					{
						line = (t_str) ft_calloc(128, sizeof(char));
						ft_strlcat(line, "mv vgrmheader ", 128);
						ft_strlcat(line, v[i], 128);
						system(line);
						ft_printf("%s: Removed header!\n", v[i]);
						free(line);
					}
					else 
					{
						ft_printf("%s: Has no header!\n", v[i]);
					}
					system("rm -rf vgrmheader");
				}
			}
			i++;
		}

	}
	return (0);
}
