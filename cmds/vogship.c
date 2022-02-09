/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vogship.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:47:59 by amenadue          #+#    #+#             */
/*   Updated: 2022/02/09 22:13:02 by amenadue         ###   ########.fr       */
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
					tmp = vg_run("curl -s https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/versionstring -o /tmp/vogshipver; cat /tmp/vogshipver");
					printf("Updated to %s", tmp);
					vg_run("git clone git@github.com:IsCoffeeTho/42vogship.git /tmp/vogship; clear; make all -C /tmp/vogship; rm -rf /tmp/vogship");
					vg_run("rm -rf /tmp/vogshipver");
				}
				else
				{
					tmp = vg_run("curl -s https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/versionstring -o /tmp/vogshipver; cat /tmp/vogshipver");

					if (strcmp(tmp, "cat: /tmp/vogshipver: No such file or directory"))
					{
						if (strcmp(tmp, VG_VER))
						{
							printf("Updated to %s", tmp);
							vg_run("git clone git@github.com:IsCoffeeTho/42vogship.git /tmp/vogship; clear; make all -C /tmp/vogship; rm -rf /tmp/vogship");
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
					vg_run("rm -rf /tmp/vogshipver");
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
	return (0);
}
