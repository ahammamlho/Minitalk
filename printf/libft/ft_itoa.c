/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:54:03 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/22 17:44:42 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int nbr)
{
	int	len;
	int	mod;

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

static char	*ft_reverse(char *src)
{
	char	temp;
	int		len;
	int		i;

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

static char	*ft_handle(int z)
{
	if (z == 0)
		return (ft_strdup("0"));
	return (ft_strdup("-2147483648"));
}

char	*ft_itoa(int n)
{
	char	*result;
	int		temp;
	int		mod;
	int		i;

	i = 0;
	temp = n;
	if (n == 0 || n == -2147483648)
		return (ft_handle(n));
	if (temp < 0)
		temp = -temp;
	result = (char *)malloc(ft_nbrlen(n) + 1);
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
	return (ft_reverse(result));
}

// int main()
// {
// 	printf("|%s|\n" , ft_itoa(-2147483648));
// }
// char	*ft_itoa(int n)
// {
// 	char	*result;
// 	int		nbr;
// 	int		mod;	
// 	nbr = n;
// 	mod = 0;
// 	// if (n == 0)
// 	// 	return (zero(0));
// 	// if (n == -2147483648)
// 	// {
// 	// 	result = ft_add_char(result, '8');
// 	// 	nbr = -214748364;
// 	// }
// 	if (nbr < 0)
// 		nbr = -nbr;
// 	while (nbr > 0)
// 	{
// 		mod = nbr % 10;
// 		result = ft_add_char(result, mod + '0');
// 		nbr = nbr / 10;
// 	}
// 	if (n < 0)
// 		result = ft_add_char(result, '-');