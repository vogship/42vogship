/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clsyc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:39:21 by amenadue          #+#    #+#             */
/*   Updated: 2022/08/30 14:12:31 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libvg/vogship.h"

const int	g_cmdindex = 1;

int	main(void)
{
	int	freeS;
	
	freeS = ft_atoi(vg_run("df -Hk ~ | grep -oE '[0-9]+ +[0-9]+%'"));
	ft_printf("\e[92mBefore Cleanup: %d Available\e[0m\n", freeS);
	vg_runp("rm -rf ~/Library/Caches/* 2>&1");
	freeS = ft_atoi(vg_run("df -Hk ~ | grep -oE '[0-9]+ +[0-9]+%'"));
	ft_printf("\e[92mAfter Cleanup: %d Available\e[0m\n", freeS);
	return (0);
}
