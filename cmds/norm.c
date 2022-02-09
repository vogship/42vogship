/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:47:59 by amenadue          #+#    #+#             */
/*   Updated: 2022/02/09 09:05:31 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vogship.h"

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
				tmp = strdup("norminette -R CheckForbiddenSourceHeader ");
				system(strcat(tmp, v[i]));
			}
			if (endswith(v[i], ".h"))
			{
				tmp = strdup("norminette -R CheckDefine ");
				system(strcat(tmp, v[i]));
			}
			i++;
		}

	}
	return (0);
}
