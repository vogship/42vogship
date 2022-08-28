/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_internal_print_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:08:22 by amenadue          #+#    #+#             */
/*   Updated: 2022/07/11 12:05:21 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*numberlength(unsigned long number, int *length)
{
	char	*string;

	while (number >= 16)
	{
		number = number / 16;
		*length += 1;
	}
	string = (char *)malloc((*length + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	string[*length] = '\0';
	return (string);
}

int	ft_internal_printhex(t_print *arg_count, char character)
{
	unsigned int	number;
	int				length;
	char			*string;
	int				j;

	number = va_arg(arg_count->args, unsigned int);
	length = 1;
	string = numberlength(number, &length);
	length--;
	j = 0;
	while (length >= 0)
	{
		if (number % 16 < 10)
			string[length] = '0' + (number % 16);
		else if (character == 'x')
			string[length] = 'a' - 10 + (number % 16);
		else if (character == 'X')
			string[length] = 'A' - 10 + (number % 16);
		number = number / 16;
		length--;
		j++;
	}
	ft_putstr_fd(string, 1);
	free(string);
	return (j);
}

int	ft_internal_printpointer(t_print *arg_count)
{
	int				length;
	char			*string;
	unsigned long	number;
	int				j;

	number = va_arg(arg_count->args, unsigned long);
	length = 1;
	string = numberlength(number, &length);
	ft_putstr_fd("0x", 1);
	j = 2;
	length--;
	while (length >= 0)
	{
		if (number % 16 < 10)
			string[length] = '0' + (number % 16);
		else
			string[length] = 'a' + (number % 16) - 10;
		number = number / 16;
		length--;
		j++;
	}
	ft_putstr_fd(string, 1);
	free(string);
	return (j);
}

int	ft_internal_printcharacter(t_print *arg_count)
{
	ft_putchar_fd(va_arg(arg_count->args, int), 1);
	return (1);
}

int	ft_internal_printstring(t_print *arg_count)
{
	char	*string;
	int		length;

	string = va_arg(arg_count->args, char *);
	if (string == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	else
	{
		length = ft_strlen(string);
		ft_putstr_fd(string, 1);
		return (length);
	}
}
