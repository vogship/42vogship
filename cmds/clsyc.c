/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clsyc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:47:59 by amenadue          #+#    #+#             */
/*   Updated: 2022/02/23 15:04:37 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libvg/vogship.h"

const int	g_cmdindex = 1;

int	main(void)
{
	t_str	tmp;
	
	tmp = vg_run("du -Hk ~ 2>&1");
	printf("\e[92mBefore Cleanup: %s", tmp);
	vg_runp("rm -rf ~/Library/Caches/* 2>&1");
	tmp = vg_run("du -Hk ~ 2>&1");
	printf("\e[92mAfter Cleanup: %s", tmp);
	return (0);
}
