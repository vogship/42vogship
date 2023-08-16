/* ========================================================================== */
/*                                                                            */
/*                                                             /   /   \      */
/*   Made By IsCoffeeTho (Aaron Menadue)                     /    |      \    */
/*                                                          |     |       |   */
/*   ft_strmapi.c                                           |      \      |   */
/*                                                          |       |     |   */
/*   Last Edited: 08:29AM 17/08/2023                         \      |    /    */
/*                                                             \   /   /      */
/*                                                                            */
/* ========================================================================== */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*n;
	int		strlen;

	i = 0;
	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	n = (char *) malloc(strlen + 1);
	if (!n)
		return (NULL);
	while (s[i])
	{
		n[i] = f(i, s[i]);
		i++;
	}
	n[i] = '\0';
	return (n);
}
