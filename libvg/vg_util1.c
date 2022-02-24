/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vg_util1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:35:19 by coffee            #+#    #+#             */
/*   Updated: 2022/02/24 16:19:59 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vogship.h"

int	regex(const t_str s, const t_str w)
{
	int	sl;
	int	wl;
	int	i;
	int	j;

	sl = ft_strlen(s);
	wl = ft_strlen(w);
	i = 0;
	if (sl > wl)
	{
		while (s[i + wl])
		{
			j = 0;
			while (s[i + j] == w[j] || w[j] == '!')
				if ((j++) == (wl - 1))
					return (1);
			i++;
		}	
	}
	return (0);
}
