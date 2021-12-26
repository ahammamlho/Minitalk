/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:02:10 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/25 11:34:15 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_left_min_char(char **str, char c, char *flags)
{
	int	i;

	i = -1;
	if (ft_char_in_strig(flags, '-') != -1)
	{
		ft_add_char(*str, c);
		ft_add_n_char(str, ' ', ft_atoi(flags) - 1);
	}
	else
	{
		ft_add_n_char(str, ' ', ft_atoi(flags + 1));
		ft_add_char(*str, c);
	}
}

void	ft_flags_left_min(char **str, char *temp, char *flags)
{
	int	i;

	i = -1;
	if (ft_char_in_strig(flags, '-') != -1)
	{
		while (temp[++i])
			*str = ft_add_char(*str, temp[i]);
		ft_add_n_char(str, ' ', ft_atoi(flags + 1) - ft_strlen(temp));
	}
	else
	{
		ft_add_n_char(str, ' ', ft_atoi(flags) - ft_strlen(temp));
		while (temp[++i])
			*str = ft_add_char(*str, temp[i]);
	}
}

void	ft_flags_left_min_decimal(char **str, char *temp, char *flags, char c)
{
	int	i;

	i = -1;
	if (ft_char_in_strig(flags, '-') != -1)
	{
		while (temp[++i])
			*str = ft_add_char(*str, temp[i]);
		if (ft_char_in_strig(flags, '+') != -1
			|| ft_char_in_strig(flags, ' ') != -1)
			ft_add_n_char(str, c, ft_atoi(flags + 2) - ft_strlen(temp));
		else
			ft_add_n_char(str, c, ft_atoi(flags + 1) - ft_strlen(temp));
	}
	else
	{
		if (ft_char_in_strig(flags, '+') != -1
			|| ft_char_in_strig(flags, ' ') != -1)
			ft_add_n_char(str, c, ft_atoi(flags + 1) - ft_strlen(temp));
		else
			ft_add_n_char(str, c, ft_atoi(flags) - ft_strlen(temp));
		while (temp[++i])
			*str = ft_add_char(*str, temp[i]);
	}
}

void	ft_flags_left_min_hex(char **str, char *temp, char *flags, char c)
{
	int	i;

	i = -1;
	if (ft_char_in_strig(flags, '-') != -1)
	{
		while (temp[++i])
			*str = ft_add_char(*str, temp[i]);
		ft_add_n_char(str, c,
			ft_atoi(flags + ft_min_width(flags, 1)) - ft_strlen(temp));
	}
	else
	{
		ft_add_n_char(str, c,
			ft_atoi(flags + ft_min_width(flags, 1)) - ft_strlen(temp));
		while (temp[++i])
			*str = ft_add_char(*str, temp[i]);
	}
}

void	ft_free(char **p1, char **p2, char **p3)
{
	if (p1)
		free(*p1);
	if (p2)
		free(*p2);
	if (p3)
		free(*p3);
}
