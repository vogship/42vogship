/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:47:59 by amenadue          #+#    #+#             */
/*   Updated: 2022/02/24 16:40:01 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libvg/vogship.h"

const int	g_cmdindex = 7;

int	main(int c, t_str *v)
{
	t_str tmp;
	int	i;

	i = 1;
	if (c == 1)
	{
		printf("Usage: ");
		vg_cmdhelp(g_cmdindex);
		nl();
	}
	else
	{
		while (i < c)
		{
			if (endswith(v[i], ".c"))
			{
				tmp = ft_strdup("norminette -R CheckForbiddenSourceHeader ");
				vg_runp((t_str)ft_strlcat(tmp, v[i], 128));
			}
			if (endswith(v[i], ".h"))
			{
				tmp = ft_strdup("norminette -R CheckDefine ");
				vg_runp((t_str)ft_strlcat(tmp, v[i], 128));
			}
			i++;
		}

	}
	return (0);
}
