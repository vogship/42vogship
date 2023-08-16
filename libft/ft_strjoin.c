/* ========================================================================== */
/*                                                                            */
/*                                                             /   /   \      */
/*   Made By IsCoffeeTho (Aaron Menadue)                     /    |      \    */
/*                                                          |     |       |   */
/*   ft_strjoin.c                                           |      \      |   */
/*                                                          |       |     |   */
/*   Last Edited: 08:29AM 17/08/2023                         \      |    /    */
/*                                                             \   /   /      */
/*                                                                            */
/* ========================================================================== */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;
	char	*new;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	new = (char *) malloc(s1len + s2len);
	if (!new)
		return (NULL);
	i = 0;
	while (i < s1len)
	{
		new[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2len)
	{
		new[s1len + i] = s2[i];
		i++;
	}
	new[s1len + s2len] = '\0';
	return (new);
}
