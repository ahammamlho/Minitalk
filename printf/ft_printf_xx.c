/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:21:52 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/25 13:49:57 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_part_of_hex(char **str, char **temp, char **s_nbr, char *flags)
{
	int	i;

	i = -1;
	while ((*s_nbr)[++i] && (*s_nbr)[0] != 0)
		*temp = ft_add_char(*temp, (*s_nbr)[i]);
	if ((*s_nbr)[0] == 0 && ft_char_in_strig(flags, '.') != -1
		&& ft_atoi(flags + ft_char_in_strig(flags, '.') + 1) > 0)
		;
	else if ((*s_nbr)[0] == 0 && ft_is_flag_zero(flags) != -1)
		;
	else if ((*s_nbr)[0] == 0)
		*temp = ft_add_char(*temp, '0');
	ft_flags_left_min_hex(str, *temp, flags, ' ');
	ft_free(temp, s_nbr, 0);
}

void	ft_print_num_hex_l(char **str, int nbr, int is_lower, char *flags)
{
	char	*s_nbr;
	char	*temp;
	int		n;

	temp = (char *)ft_calloc(1, sizeof(char));
	s_nbr = ft_calloc(1, sizeof(char));
	s_nbr = ft_int_32base(nbr, s_nbr, is_lower);
	if (ft_char_in_strig(flags, '#') != -1 && nbr != 0)
	{
		temp = ft_add_char(temp, '0');
		if (is_lower)
			temp = ft_add_char(temp, 'x');
		else
			temp = ft_add_char(temp, 'X');
	}
	n = ft_atoi(flags + ft_min_width(flags, ft_is_flag_zero(flags)) + 1)
		- ft_strlen(temp) - ft_strlen(s_nbr);
	if (ft_char_in_strig(flags, '.') != -1)
		ft_add_n_char(&temp, '0', ft_atoi(flags + ft_char_in_strig(flags, '.')
				+ 1) - ft_strlen(s_nbr));
	else if (ft_is_flag_zero(flags) != -1)
		ft_add_n_char(&temp, '0', n);
	ft_part_of_hex(str, &temp, &s_nbr, flags);
}
