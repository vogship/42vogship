/* ========================================================================== */
/*                                                                            */
/*                                                             /   /   \      */
/*   Made By IsCoffeeTho (Aaron Menadue)                     /    |      \    */
/*                                                          |     |       |   */
/*   vg_cmds.c                                              |      \      |   */
/*                                                          |       |     |   */
/*   Last Edited: 08:24AM 17/08/2023                         \      |    /    */
/*                                                             \   /   /      */
/*                                                                            */
/* ========================================================================== */

#include "vogship.h"

const t_vgcmd	g_cmdlist[VG_COMMAND_COUNT] = {
{
	.cmd = "car",
	.cmdflgs = "<files>",
	.desc = "Compiles, Runs, and Returns."
},
{
	.cmd = "clsyc",
	.cmdflgs = NULL,
	.desc = "Cleans up system for more storage."
},
{
	.cmd = "cls",
	.cmdflgs = NULL,
	.desc = "Clears the screen."
},
{
	.cmd = "compile",
	.cmdflgs = "[<gcc parameters>] <files>",
	.desc = "Compiles anything with -Wall -Wextra -Werror."
},
{
	.cmd = "genhead",
	.cmdflgs = "<files>",
	.desc = "Puts the :Stdheader in the specified files without duplicates."
},
{
	.cmd = "rsthead",
	.cmdflgs = "<files>",
	.desc = "Clears the :Stdheader from specified files."
},
{
	.cmd = "medir",
	.cmdflgs = "<name>",
	.desc = "Create and Enter a directory."
},
{
	.cmd = "norm",
	.cmdflgs = "<files>",
	.desc = "Runs Norminette on each file with the correct flags for each file."
},
{
	.cmd = "vogship",
	.cmdflgs = "<flags>",
	.desc = "The Vogship command helping you soar through 42 Terminal."
}
};

void	vg_cmdinfo(t_vgcmd vgcmd)
{
	ft_printf("\e[96m\e[48;5;235m %s", vgcmd.cmd);
	if (vgcmd.cmdflgs != NULL)
	{
		ft_printf(" \e[94m%s", vgcmd.cmdflgs);
	}
	ft_printf(" \e[0m");
}

void	vg_cmdlist(void)
{
	int		i;
	t_vgcmd	currcmd;

	i = 0;
	while (i < VG_COMMAND_COUNT)
	{
		ft_printf("   ");
		currcmd = g_cmdlist[i];
		vg_cmdinfo(currcmd);
		ft_printf(" %s\n", currcmd.desc);
		i++;
	}
}

void	vg_cmdhelp(int i)
{
	vg_cmdinfo(g_cmdlist[i]);
}
