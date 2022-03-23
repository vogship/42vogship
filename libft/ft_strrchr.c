/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:55:40 by amenadue          #+#    #+#             */
/*   Updated: 2022/03/17 23:01:58 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*a;

	a = NULL;
	if (c == '\0')
	{
		while (*s)
			s++;
		a = (char *) s;
		return (a);
	}
	while (*s)
	{
		if (*s == c)
			a = (char *) s;
		s++;
	}
	return (a);
}
