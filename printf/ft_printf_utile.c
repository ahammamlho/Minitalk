/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:36:37 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/25 13:53:32 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen( int nbr)
{
	int	len;
	int	mod;

	len = 1;
	if (nbr == 0)
		return (1);
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
