/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:51:31 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/24 17:12:03 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_char(char *src, char c)
{
	int		lent_src;
	char	*result;
	int		i;

	result = 0;
	lent_src = ft_strlen(src);
	result = (char *) ft_calloc(lent_src + 2, sizeof(char));
	i = 0;
	while (i < lent_src)
	{
		result[i] = src[i];
		i++;
	}
	if (src)
		free(src);
	result[i] = c;
	result[i + 1] = '\0';
	return (result);
}

char	*ft_int_base(uintptr_t nbr, char *res)
{
	int		len_base;
	char	*base;

	base = "0123456789abcdef";
	len_base = ft_strlen(base);
	if (nbr < 0)
	{
		nbr = -1 * nbr;
		res = ft_add_char(res, '-');
	}
	if (nbr > 0)
	{
		res = ft_int_base(nbr / len_base, res);
		res = ft_add_char(res, base[nbr % len_base]);
	}
	return (res);
}

char	*ft_int_32base(u_int32_t nbr, char *res, int is_lower)
{
	int		len_base;
	char	*base;

	if (is_lower)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	len_base = ft_strlen(base);
	if (nbr < 0)
	{
		nbr = -1 * nbr;
		res = ft_add_char(res, '-');
	}
	if (nbr > 0)
	{
		res = ft_int_32base(nbr / len_base, res, is_lower);
		res = ft_add_char(res, base[nbr % len_base]);
	}
	return (res);
}
