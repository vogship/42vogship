/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vogship.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:47:59 by amenadue          #+#    #+#             */
/*   Updated: 2022/02/09 07:06:27 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vogship.h"

const int	g_cmdindex = 7;

int	main(int c, t_str *v)
{
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
					printf("\e[91mForcing Update\e[0m");
				}
				else
				{
					printf("\e[91mChecking for update\e[0m");
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
