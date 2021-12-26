/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:59:56 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/25 12:52:18 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char **str, char c, char **index, char *flags)
{
	char	*res;
	int		i;
	char	*temp;

	res = 0;
	temp = ft_calloc(1, sizeof(char));
	i = -1;
	if (c == 0)
	{
		if (ft_strlen(flags) == 1)
			res = ft_itoa(ft_strlen(*str));
		else if (ft_char_in_strig(flags, '-') == -1)
			res = ft_itoa(ft_strlen(*str) + ft_atoi(flags) - 1);
		else
			res = ft_itoa(ft_strlen(*str));
		while (res[++i])
			*index = ft_add_char(*index, res[i]);
		*index = ft_add_char(*index, '|');
	}
	if (c)
		temp = ft_add_char(temp, c);
	else
		temp = ft_add_char(temp, 'c');
	ft_flags_left_min(str, temp, flags);
	ft_free(&temp, &res, 0);
}

void	ft_print_string(char **str, char *s, char *flags)
{
	char	*temp;
	char	*sub;

	sub = 0;
	if (s == NULL)
		temp = ft_strdup("(null)");
	else
		temp = ft_strdup(s);
	if (ft_char_in_strig(flags, '.') != -1)
		sub = ft_substr(temp, 0,
				ft_atoi(flags + ft_char_in_strig(flags, '.') + 1));
	else
		sub = temp;
	ft_flags_left_min(str, sub, flags);
	free(temp);
	if (ft_char_in_strig(flags, '.') != -1)
		free(sub);
}

void	ft_print_pointer(char **str, void *ptr, char *flags)
{
	int			i;
	char		*res;
	char		*temp;
	uintptr_t	p;

	p = (uintptr_t)ptr;
	res = ft_calloc(1, sizeof(char));
	temp = ft_calloc(1, sizeof(char));
	res = ft_int_base(p, res);
	i = -1;
	temp = ft_add_char(temp, '0');
	temp = ft_add_char(temp, 'x');
	if (!ptr)
		temp = ft_add_char(temp, '0');
	while (ptr && res[++i])
		temp = ft_add_char(temp, res[i]);
	ft_flags_left_min(str, temp, flags);
	free(temp);
	free(res);
}
