/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:06:04 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/05 20:22:21 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	unsigned int	i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)ptr;
	while (i < n)
	{
		*(temp + i) = 0;
		i++;
	}
}
