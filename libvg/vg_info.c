/* ========================================================================== */
/*                                                                            */
/*                                                             /   /   \      */
/*   Made By IsCoffeeTho (Aaron Menadue)                     /    |      \    */
/*                                                          |     |       |   */
/*   vg_info.c                                              |      \      |   */
/*                                                          |       |     |   */
/*   Last Edited: 08:23AM 17/08/2023                         \      |    /    */
/*                                                             \   /   /      */
/*                                                                            */
/* ========================================================================== */

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
	ft_printf("\e[94m\e[48;5;235m     / /  |/| |             \e[48;5;235m\e[0m\n");
	ft_printf("\e[94m\e[48;5;235m   / /__   / /              \e[48;5;235m\e[0m\n");
	ft_printf("\e[94m\e[48;5;235m /____  | | |/|  █  Vogship \e[48;5;235m\e[0m\n");
	ft_printf("\e[94m\e[48;5;235m      | |                   \e[48;5;235m\e[0m\n");
}

void	vg_version(void)
{
	ft_printf("\e[92mVersion %s\e[0m\n", VG_VER);
}

void	vg_author(void)
{
	ft_printf("\e[96mWritten by %s\e[0m\n", VG_AUTHOR);
}

void	vg_contributors(void)
{
	int	i;

	i = 0;
	ft_printf("\e[96mContributions from:\e[0m\n");
	while (g_vg_contributors[i])
		ft_printf("    %s\n", g_vg_contributors[i++]);
}
