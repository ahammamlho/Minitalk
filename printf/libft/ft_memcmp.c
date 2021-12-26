/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:09:54 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/07 17:18:01 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t					i;
	unsigned char			*t_str1;
	unsigned char			*t_str2;

	i = 0;
	t_str1 = (unsigned char *)str1;
	t_str2 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	while (t_str1[i] == t_str2[i] && i < n - 1)
		i++;
	return (t_str1[i] - t_str2[i]);
}

// int main()
// {
// 	char s1[] = "ahamma";
// 	char s2[] = "ahammb";

// 	printf("-->%d", ft_memcmp(s1,s2,5));
// }
