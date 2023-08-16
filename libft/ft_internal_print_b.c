/* ========================================================================== */
/*                                                                            */
/*                                                             /   /   \      */
/*   Made By IsCoffeeTho (Aaron Menadue)                     /    |      \    */
/*                                                          |     |       |   */
/*   ft_internal_print_b.c                                  |      \      |   */
/*                                                          |       |     |   */
/*   Last Edited: 08:28AM 17/08/2023                         \      |    /    */
/*                                                             \   /   /      */
/*                                                                            */
/* ========================================================================== */

#include "libft.h"

static int	numberlength(unsigned int number)
{
	int	length;

	length = 1;
	while (number > 9)
	{
		number = number / 10;
		length++;
	}
	return (length);
}

static char	*ft_internal_itoa(unsigned int number)
{
	char	*string;
	int		length;

	length = numberlength(number);
	string = (char *)malloc(length + 1 * sizeof(char));
	if (string == NULL)
		return (NULL);
	string[length] = '\0';
	while (length > 0)
	{
		string[--length] = number % 10 + '0';
		number = number / 10;
	}
	return (string);
}

int	ft_internal_printint(t_print *arg_count)
{
	char	*string;
	int		result;

	result = va_arg(arg_count->args, int);
	string = ft_itoa(result);
	ft_putstr_fd(string, 1);
	free(string);
	return (ft_strlen(string));
}

int	ft_internal_printunsignedint(t_print *arg_count)
{
	char			*string;
	unsigned int	result;

	result = va_arg(arg_count->args, unsigned int);
	string = ft_internal_itoa(result);
	ft_putstr_fd(string, 1);
	free(string);
	return (ft_strlen(string));
}
