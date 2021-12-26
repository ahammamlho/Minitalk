/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:45:30 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/25 13:53:12 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_unsigned_nbrlen(unsigned int nbr)
{
	unsigned int	len;
	unsigned int	mod;

	len = 1;
	if (nbr > 0)
		mod = nbr / 10;
	else
	{
		mod = -nbr / 10;
		len++;
	}	
	while (mod > 0)
	{
		len++;
		mod = mod / 10;
	}
	return (len);
}

static char	*ft_unsigned_reverse(char *src)
{
	char				temp;
	unsigned int		len;
	unsigned int		i;

	i = 0;
	len = ft_strlen((const char *)src);
	while (i < len / 2)
	{
		temp = src[i];
		src[i] = src[len - 1 - i];
		src[len - 1 - i] = temp;
		i++;
	}
	return (src);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char				*result;
	unsigned int		temp;
	unsigned int		mod;
	unsigned int		i;

	i = 0;
	temp = n;
	if (n == 0)
		return (ft_strdup("0"));
	if (temp < 0)
		temp = -temp;
	result = (char *)malloc (ft_unsigned_nbrlen(n) + 1);
	if (!result)
		return (0);
	while (temp > 0)
	{
		mod = temp % 10;
		result[i] = mod + '0';
		temp = temp / 10;
		i++;
	}
	if (n < 0)
		result[i++] = '-';
	result[i] = '\0';
	return (ft_unsigned_reverse(result));
}
