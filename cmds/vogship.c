/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vogship.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:47:59 by amenadue          #+#    #+#             */
/*   Updated: 2022/03/24 15:10:25 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libvg/vogship.h"

const int	g_cmdindex = 7;

int	main(int c, t_str *v)
{
	t_str tmp;
	int	pnl;

	pnl = 1;
	if (c == 2)
	{
		if (startswith(v[1], "-"))
		{
			if (contains(v[1], 'v'))
			{
				vg_version();
				pnl = 0;
			}
			else if (contains(v[1], 'h'))
			{
				printf("\e[92mCommands Available:\e[0m\n");
				vg_cmdlist();
			}
			else if (contains(v[1], 'u'))
			{
				if (contains(v[1], 'f'))
				{
					printf("\e[91mReinstalling update\e[0m");
					tmp = vg_run("curl -s https://raw.githubusercontent.com/vogship/42vogship/master/versionstring -o vogshipver; cat vogshipver; rm vogshipver");
					printf("Updated to %s", tmp);
					vg_run("git clone https://github.com/vogship/42vogship.git vogship; clear; make all -s -C vogship; rm -rf vogship");
				}
				else
				{
					tmp = vg_run("curl -s https://raw.githubusercontent.com/vogship/42vogship/master/versionstring -o vogshipver; cat vogshipver; rm vogshipver");

					if (ft_strncmp(tmp, "cat: vogshipver: No such file or directory", 48))
					{
						if (ft_strncmp(tmp, VG_VER, 20))
						{
							printf("Updated to %s", tmp);
							vg_run("git clone https://github.com/vogship/42vogship.git vogship; clear; make all -C vogship; rm -rf vogship");
						}
						else
						{
							printf("Already Up to Date!\n");
							vg_version();
							pnl = 0;
						} 
					} else {
						printf("Please check your internet");
					}
					vg_run("rm -rf vogshipver");
				}
			}
			else
			{
				printf("\e[91mInvalid Flag\e[0m");
			}
		}
		else
		{
			printf("\e[91mInvalid Argument\e[0m");
		}
	}
	else
	{
		vg_icon();
		printf("\n\e[92mMade by Developers for Developers\e[0m\n");
		vg_author();
		vg_contributors();
	}
	if (pnl) nl();
	if (tmp)
		free(tmp);
	return (0);
}
