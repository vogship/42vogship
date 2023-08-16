/* ========================================================================== */
/*                                                                            */
/*                                                             /   /   \      */
/*   Made By IsCoffeeTho (Aaron Menadue)                     /    |      \    */
/*                                                          |     |       |   */
/*   ft_memcmp.c                                            |      \      |   */
/*                                                          |       |     |   */
/*   Last Edited: 08:28AM 17/08/2023                         \      |    /    */
/*                                                             \   /   /      */
/*                                                                            */
/* ========================================================================== */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_str;
	unsigned char	*s2_str;

	if (n <= 0)
		return (0);
	s1_str = (unsigned char *) s1;
	s2_str = (unsigned char *) s2;
	while (*s1_str == *s2_str && n - 1 > 0)
	{
		s1_str++;
		s2_str++;
		n--;
	}
	return (*s1_str - *s2_str);
}
