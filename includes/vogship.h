/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vogship.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:48:03 by amenadue          #+#    #+#             */
/*   Updated: 2022/02/09 08:40:34 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VOGSHIP_H
# define VOGSHIP_H "v2.0"

# include <string.h>
# include <stdio.h>
# include <stdlib.h>

# define VG_VER "v2.0"
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

int		regex(const t_str s, const t_str w);

#endif