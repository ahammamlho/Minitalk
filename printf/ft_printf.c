/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:23:45 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/25 14:28:13 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putresultat(char *result, char *index)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = ft_atoi(index);
	while (result && result[i])
	{
		if (ft_strlen(index) && nbr == i)
		{
			write(1, "", 1);
			index = index + ft_nbrlen(nbr) + 1;
			nbr = ft_atoi(index);
		}
		else
			write(1, &result[i], 1);
		i++;
	}
	return (i);
}

static void	ft_body_printf(va_list list, char **res, char **ind, char *flags)
{
	if (flags[ft_strlen(flags) - 1] == 'c')
		ft_print_char(res, va_arg(list, int), ind, flags);
	if (flags[ft_strlen(flags) - 1] == 's')
		ft_print_string(res, va_arg(list, char *), flags);
	if (flags[ft_strlen(flags) - 1] == 'p')
		ft_print_pointer(res, va_arg(list, void *), flags);
	if (flags[ft_strlen(flags) - 1] == 'd'
		|| flags[ft_strlen(flags) - 1] == 'i')
		ft_print_decimal(res, va_arg(list, int), flags);
	if (flags[ft_strlen(flags) - 1] == 'u')
		ft_print_unsigned_decimal(res, va_arg(list, unsigned int), flags);
	if (flags[ft_strlen(flags) - 1] == 'x')
		ft_print_num_hex_l(res, va_arg(list, int), 1, flags);
	if (flags[ft_strlen(flags) - 1] == 'X')
		ft_print_num_hex_l(res, va_arg(list, int), 0, flags);
	if (flags[ft_strlen(flags) - 1] == '%')
		*res = ft_add_char(*res, '%');
}

static void	ft_init(char **result, char **index, char **flags, int *i)
{
	*i = -1;
	*flags = (char *)ft_calloc(1, sizeof(char));
	*result = (char *)ft_calloc(1, sizeof(char));
	*index = (char *)ft_calloc(1, sizeof(char));
}

int	ft_printf(const char *str, ...)
{
	char		*result;
	va_list		list;
	int			i;
	char		*index;
	char		*flags;

	va_start(list, str);
	ft_init(&result, &index, &flags, &i);
	while (str && str[++i])
	{
		if (str[i] == '%')
		{
			ft_add_flags(str, &i, &flags);
			ft_body_printf(list, &result, &index, flags);
		}
		else
			result = ft_add_char(result, str[i]);
		ft_bzero(flags, ft_strlen(flags));
	}
	va_end(list);
	i = ft_putresultat(result, index);
	ft_free(&result, &index, &flags);
	return (i);
}

// # include <stdio.h>
// # define STR "--|%c|--\n", '2'
// int main()
// {
// 	//int u = ft_printf(STR);
//  	// int t = printf(STR);
// 	//printf("%d---%d", u , t);
// }
