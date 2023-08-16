/* ========================================================================== */
/*                                                                            */
/*                                                             /   /   \      */
/*   Made By IsCoffeeTho (Aaron Menadue)                     /    |      \    */
/*                                                          |     |       |   */
/*   vogship.h                                              |      \      |   */
/*                                                          |       |     |   */
/*   Last Edited: 08:23AM 17/08/2023                         \      |    /    */
/*                                                             \   /   /      */
/*                                                                            */
/* ========================================================================== */

#ifndef VOGSHIP_H
# define VOGSHIP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

# define VG_VER "2.1.1"
# define VG_AUTHOR "IsCoffeeTho"

# define VG_PREFERENCE_FILE "~/.vg_prefs.ini"
# define VG_TMP_PREF_FILE "~/.tmp_vg_prefs.ini"

typedef char*	t_str;

typedef struct s_vgcmd
{
	t_str	cmd;
	t_str	cmdflgs;
	t_str	desc;
}	t_vgcmd;

# define VG_COMMAND_COUNT 9

void	vg_icon(void);
void	vg_version(void);
void	vg_author(void);
void	vg_contributors(void);
void	vg_cmdinfo(t_vgcmd vgcmd);
void	vg_cmdlist(void);
void	vg_cmdhelp(int i);
int		startswith(const t_str s, const t_str w);
int		endswith(const t_str s, const t_str w);
int		contains(t_str s, char l);
void	nl(void);
t_str	vg_run(const t_str cmd);
void	vg_runp(const t_str cmd);
int		regex(const t_str s, const t_str w);
int		vg_stdheader(t_str filepath);
char	*vg_get_pref(char *preference_name, char *default_value);
int		vg_set_pref(char *preference_name, char *value);
int		vg_del_pref(char *preference_name);

#endif
