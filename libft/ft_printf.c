/* ========================================================================== */
/*                                                                            */
/*                                                             /   /   \      */
/*   Made By IsCoffeeTho (Aaron Menadue)                     /    |      \    */
/*                                                          |     |       |   */
/*   ft_printf.c                                            |      \      |   */
/*                                                          |       |     |   */
/*   Last Edited: 08:28AM 17/08/2023                         \      |    /    */
/*                                                             \   /   /      */
/*                                                                            */
/* ========================================================================== */

#include "libft.h"

static t_print	*start(void)
{
	t_print	*arg_count;

	arg_count = (t_print *)malloc(sizeof(t_print));
	if (arg_count == NULL)
		return (NULL);
	return (arg_count);
}

static int	printcheck(const char character, t_print *arg_count)
{
	if (character == 'c')
		return (ft_internal_printcharacter(arg_count));
	else if (character == 's')
		return (ft_internal_printstring(arg_count));
	else if (character == 'p')
		return (ft_internal_printpointer(arg_count));
	else if (character == 'i' || character == 'd')
		return (ft_internal_printint(arg_count));
	else if (character == 'u')
		return (ft_internal_printunsignedint(arg_count));
	else if (character == 'x' || character == 'X')
		return (ft_internal_printhex(arg_count, character));
	else if (character == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else if (character != '\0')
	{
		write(1, &character, 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *string, ...)
{
	t_print	*arg_count;
	int		i;
	int		j;

	i = 0;
	arg_count = start();
	j = 0;
	va_start(arg_count->args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
			j += printcheck(string[++i], arg_count);
		else
		{
			ft_putchar_fd(string[i], 1);
			j++;
		}
		if (string[i] != '\0')
			i++;
	}
	va_end(arg_count->args);
	free(arg_count);
	return (j);
}
