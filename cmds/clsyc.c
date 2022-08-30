/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clsyc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:39:21 by amenadue          #+#    #+#             */
/*   Updated: 2022/05/02 15:24:27 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libvg/vogship.h"

const int	g_cmdindex = 1;

int	main(void)
{
	int	freeS;
	
	freeS = ft_atoi(vg_run("df -Hk ~ 2>&1"));
	ft_printf("\e[92mBefore Cleanup: %d Available\e[0m", freeS);
	vg_runp("rm -rf ~/Library/Caches/* 2>&1");
	freeS = ft_atoi(vg_run("df -Hk ~ 2>&1"));
	ft_printf("\e[92mAfter Cleanup: %d Available\e[0m", freeS);
	return (0);
}
