/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vogship.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:35:19 by coffee            #+#    #+#             */
/*   Updated: 2022/02/09 20:03:16 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VOGSHIP_H
# define VOGSHIP_H "v2.0 Turbo"

# include <string.h>
# include <stdio.h>

# define VG_VER "v2.0 Turbo"
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

#endif
