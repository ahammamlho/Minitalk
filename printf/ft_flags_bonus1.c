/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:40:52 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/25 12:14:35 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char_in_strig(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

void	ft_add_flags(const char *str, int *i, char **flags)
{
	int	j;

	j = 1;
	(*i)++;
	while (j)
	{
		*flags = ft_add_char(*flags, str[*i]);
		if (ft_char_in_strig("cspdiuxX", str[*i]) != -1
			|| str[*i] == '%')
			j = 0;
		(*i)++;
	}
	(*i)--;
}

int	ft_is_flag_zero(char *flags)
{
	int	i;

	i = 0;
	while (flags[i] && flags[i] != '.')
	{
		if (flags[i] >= '1' && flags[i] <= '9')
			return (-1);
		else if (flags[i] == '0')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_min_width(char *flags, int idx)
{
	int	i;

	i = 0;
	while (flags[idx + i])
	{
		if (flags[idx + i] >= '0' && flags[idx + i] <= '9')
			return (idx + i);
		i++;
	}
	return (0);
}

void	ft_add_n_char(char **res, char c, int n)
{
	int	i;

	i = -1;
	if (n > 0)
	{
		while (++i < n)
			*res = ft_add_char(*res, c);
	}
}
