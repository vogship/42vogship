/* ========================================================================== */
/*                                                                            */
/*                                                             /   /   \      */
/*   Made By IsCoffeeTho (Aaron Menadue)                     /    |      \    */
/*                                                          |     |       |   */
/*   vg_util1.c                                             |      \      |   */
/*                                                          |       |     |   */
/*   Last Edited: 08:24AM 17/08/2023                         \      |    /    */
/*                                                             \   /   /      */
/*                                                                            */
/* ========================================================================== */

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
