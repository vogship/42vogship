/* ========================================================================== */
/*                                                                            */
/*                                                             /   /   \      */
/*   Made By IsCoffeeTho (Aaron Menadue)                     /    |      \    */
/*                                                          |     |       |   */
/*   ft_strlcpy.c                                           |      \      |   */
/*                                                          |       |     |   */
/*   Last Edited: 08:29AM 17/08/2023                         \      |    /    */
/*                                                             \   /   /      */
/*                                                                            */
/* ========================================================================== */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const size_t	slen = ft_strlen(src) + 1;

	if (slen < dstsize)
		ft_memcpy(dst, src, slen);
	else if (dstsize != 0)
	{
		dstsize--;
		ft_memcpy(dst, src, dstsize);
		dst[dstsize] = '\0';
	}
	return (slen - 1);
}
