/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vg_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:35:19 by coffee            #+#    #+#             */
/*   Updated: 2022/02/09 20:05:01 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vogship.h"

const t_str	g_vg_contributors[5] = {
	"Byron Hawksmith",
	"Jaymie Gobbett",
	"Pasquale Rossi",
	"Tomas Turner",
	"Coby J. Morris"
};

void	vg_icon(void)
{
	printf("\e[94m\e[48;5;235m     / /  |/| |             \e[48;5;235m\e[0m\n");
	printf("\e[94m\e[48;5;235m   / /__   / /              \e[48;5;235m\e[0m\n");
	printf("\e[94m\e[48;5;235m /____  | | |/|  █  Vogship \e[48;5;235m\e[0m\n");
	printf("\e[94m\e[48;5;235m      | |                   \e[48;5;235m\e[0m\n");
}

void	vg_version(void)
{
	printf("\e[92mVersion %s\e[0m\n", VG_VER);
}

void	vg_author(void)
{
	printf("\e[96mWritten by %s\e[0m\n", VG_AUTHOR);
}

void	vg_contributors(void)
{
	int	i;

	i = 0;
	printf("\e[96mContributions from:\e[0m\n");
	while (g_vg_contributors[i])
	{
		printf("    %s\n", g_vg_contributors[i]);
		i++;
	}
}
