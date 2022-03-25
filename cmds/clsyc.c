/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clsyc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:39:21 by amenadue          #+#    #+#             */
/*   Updated: 2022/03/24 15:17:42 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libvg/vogship.h"

const int	g_cmdindex = 1;

int	main(void)
{
	t_str	tmp;
	
	tmp = vg_run("du -Hk ~ 2>&1");
	printf("\e[92mBefore Cleanup: %s\n", tmp);
	vg_runp("rm -rf ~/Library/Caches/* 2>&1");
	tmp = vg_run("du -Hk ~ 2>&1");
	printf("\e[92mAfter Cleanup: %s\n", tmp);
	return (0);
}