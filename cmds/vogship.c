/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vogship.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:47:59 by amenadue          #+#    #+#             */
/*   Updated: 2022/07/20 23:55:27 by amenadue         ###   ########.fr       */
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
				if (contains(v[1], 'c'))
				{
					tmp = vg_run("curl -s https://raw.githubusercontent.com/vogship/42vogship/master/versionstring -o vogshipver; cat vogshipver; rm vogshipver");
					if (ft_strncmp(tmp, VG_VER, 20))
					{
						if (ft_strncmp(tmp, VG_VER, 20))
							printf("\e[94mNew version Available!\e[0m\n\e[91m%s\e[0m -> \e[92m%s\e[0m\n", VG_VER, tmp);
						else if (!contains(v[1], 's'))
						{
							printf("Currently Up to date!\n");
							vg_version();
						}
					}
				}
				else
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
					printf("\e[91mReinstalling update\e[0m\n");
					tmp = vg_run("curl -s https://raw.githubusercontent.com/vogship/42vogship/master/versionstring -o vogshipver; cat vogshipver; rm vogshipver");
					printf("Updating to %s\n", tmp);
					vg_run("git clone https://github.com/vogship/42vogship.git vogship; clear; make all -s -C vogship; rm -rf vogship");
				}
				else
				{
					tmp = vg_run("curl -s https://raw.githubusercontent.com/vogship/42vogship/master/versionstring -o vogshipver; cat vogshipver; rm vogshipver");

					if (ft_strncmp(tmp, "cat: vogshipver: No such file or directory", 48))
					{
						if (ft_strncmp(tmp, VG_VER, 20))
						{
							printf("\e[Updating to %s\n", tmp);
							vg_run("git clone https://github.com/vogship/42vogship.git vogship; clear; make all -s -C vogship; rm -rf vogship");
						}
						else
						{
							printf("Already Up to Date!\n");
							vg_version();
							pnl = 0;
						} 
					}
					else
						printf("Please check your internet connection.\n");
					vg_run("rm -rf vogshipver");
				}
			}
			else
				printf("\e[91mInvalid Flag\e[0m");
		}
		else
			printf("\e[91mInvalid Argument\e[0m");
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
