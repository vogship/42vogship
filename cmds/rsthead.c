/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsthead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:47:59 by amenadue          #+#    #+#             */
/*   Updated: 2022/02/09 22:13:00 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libvg/vogship.h"

const int	g_cmdindex = 5;


int	main(int c, t_str *v)
{
	t_str	line;
	int		flag;
	int		start_writing;
    size_t	len = 0;
    ssize_t	read;

    FILE    *fp;
	FILE	*nfp;
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
			if (endswith(v[i], ".c") || endswith(v[i], ".h")) {
				flag = 0;
				start_writing = 0;
				fp = fopen(v[i], "r");
				nfp = fopen("tmprmheader", "w");
				if (!fp) {
					fprintf(stderr, "Failed to open %s\n", v[i]);
					return (1);
				}
				if (!nfp) {
					fprintf(stderr, "Failed to open %s\n", v[i]);
					return (1);
				}

				while (getline(&line, &len, fp) != -1) {
					line[strcspn(line, "\n")] = 0;
					if (start_writing)
					{
						fprintf(nfp, "%s\n", line);
					}
					else 
					{
						if (flag >= 11)
						{
							if (!strcmp(line, "")) {
								start_writing = 1;
							}
						}
						if (startswith(line, "/*") && endswith(line, "*/"))
						{
							flag++;
						}
					}
				}
				fclose(fp);
				fclose(nfp);

				if (line)
					free(line);

				line = strdup("mv tmprmheader ");
				vg_run(strcat(line, v[i]));
				vg_run("rm -rf tmprmheader");
			}
			i++;
		}

	}
	return (0);
}
