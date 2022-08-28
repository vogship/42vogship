/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vogship.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:35:19 by coffee            #+#    #+#             */
/*   Updated: 2022/07/06 18:53:33 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VOGSHIP_H
# define VOGSHIP_H

# include "../libft/libft.h"
# include <stdio.h>

# define VG_VER "v2.0 Turbo p(0.0.6)"
# define VG_AUTHOR "Aaron Menadue"

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

#endif
