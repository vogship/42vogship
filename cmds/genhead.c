/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genhead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:47:59 by amenadue          #+#    #+#             */
/*   Updated: 2022/02/24 16:40:41 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libvg/vogship.h"

const int	g_cmdindex = 4;


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
			if (endswith(v[i], ".c") || endswith(v[i], ".h")) {
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

				if (line)
					free(line);

				if (flag < 5) {
					line = ft_strdup("vim -c \"Stdheader\" -c \"wq\" ");
					vg_runp((t_str)ft_strlcat(line, v[i], 128));
					printf("%s: Generated!\n", v[i]);
				} else {
					printf("%s: Already has :Stdheader!\n", v[i]);
				}
			}
			i++;
		}
	}
	if (line)
		free(line);
	return (0);
}
