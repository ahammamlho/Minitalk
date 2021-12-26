/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:54:46 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/25 13:28:59 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_part_decimal(char **str, char **s_nbr, char **temp, char *flags)
{
	int	i;

	i = -1;
	while ((*s_nbr)[++i] && (*s_nbr)[0] != 0)
		*temp = ft_add_char((*temp), (*s_nbr)[i]);
	if ((*s_nbr)[0] == 0 && ft_strlen(flags) == 1)
		(*temp) = ft_add_char((*temp), '0');
	else if ((*s_nbr)[0] == 0 && ft_char_in_strig(flags, '.') == -1)
		(*temp) = ft_add_char((*temp), '0');
	else if ((*s_nbr)[0] == 0 && ft_char_in_strig(flags, '.') != -1
		&& ft_atoi(flags + ft_char_in_strig(flags, '.') + 1) > 0)
		(*temp) = ft_add_char((*temp), '0');
	ft_flags_left_min_decimal(str, (*temp), flags, ' ');
	ft_free(s_nbr, temp, 0);
}

void	ft_print_decimal(char **str, int nbr, char *flags)
{
	char	*s_nbr;
	char	*temp;
	int		n;

	temp = (char *)ft_calloc(1, sizeof(char));
	if (nbr == INT_MIN)
		s_nbr = ft_strdup("2147483648");
	else if (nbr < 0)
		s_nbr = ft_itoa(-nbr);
	else
		s_nbr = ft_itoa(nbr);
	if (ft_char_in_strig(flags, ' ') != -1 && nbr >= 0)
		temp = ft_add_char(temp, ' ');
	else if (ft_char_in_strig(flags, '+') != -1 && nbr >= 0)
		temp = ft_add_char(temp, '+');
	else if (nbr < 0 || nbr == INT_MIN)
		temp = ft_add_char(temp, '-');
	n = ft_atoi(flags + ft_min_width(flags, ft_is_flag_zero(flags)) + 1);
	if (ft_char_in_strig(flags, '.') != -1)
		ft_add_n_char(&temp, '0', ft_atoi(flags
				+ ft_char_in_strig(flags, '.') + 1) - ft_strlen(s_nbr));
	else if (ft_is_flag_zero(flags) != -1)
		ft_add_n_char(&temp, '0', n - ft_strlen(temp) - ft_strlen(s_nbr));
	ft_part_decimal(str, &s_nbr, &temp, flags);
}

void	ft_print_unsigned_decimal(char **str, int nbr, char *flags)
{
	char	*s_nbr;
	char	*temp;
	int		n1;
	int		n2;

	temp = (char *)ft_calloc(1, sizeof(char));
	s_nbr = ft_unsigned_itoa(nbr);
	n1 = ft_atoi(flags + ft_char_in_strig(flags, '.') + 1) - ft_strlen(s_nbr);
	n2 = ft_atoi(flags + ft_min_width(flags, ft_is_flag_zero(flags)) + 1)
		- ft_strlen(temp) - ft_strlen(s_nbr);
	if (ft_char_in_strig(flags, '.') != -1)
		ft_add_n_char(&temp, '0', n1);
	else if (ft_is_flag_zero(flags) != -1)
		ft_add_n_char(&temp, '0', n2);
	ft_part_decimal(str, &s_nbr, &temp, flags);
}
