/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:09:35 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/08 10:05:43 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char		*temp;
	size_t				i;

	i = 0;
	temp = (unsigned char *)str;
	if (!n)
		return (0);
	while (i < n)
	{
		if (temp[i] == (unsigned char )c)
			return ((void *)&temp[i]);
		i++;
	}
	return (0);
}

// #include <string.h>
// int main()
// {
// 	printf("%s\n",ft_memchr(((void *)0), '\0', 0x20));
// 	printf("%s\n",memchr(((void *)0), '\0', 0x20));
// }