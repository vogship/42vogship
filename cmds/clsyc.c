/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clsyc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:47:59 by amenadue          #+#    #+#             */
/*   Updated: 2022/02/09 08:26:19 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vogship.h"

const int	g_cmdindex = 1;

int	main(void)
{
	t_str	tmp;
	
	tmp = vg_run("du -Hk ~");
	printf("\e[92mBefore Cleanup: %s", tmp);
	system("rm -rf ~/Library/Caches/*");
	tmp = vg_run("du -Hk ~");
	printf("\e[92mAfter Cleanup: %s", tmp);
	return (0);
}
