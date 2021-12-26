/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:11:24 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/07 12:06:30 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			i;
	size_t			len_dest;

	i = 0;
	len_dest = ft_strlen(dest);
	if (len_dest >= size)
		return (ft_strlen(src) + size);
	while (size != 0 && src[i] != '\0' && (len_dest + i < size - 1))
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (ft_strlen(src) + len_dest);
}

// int main()
// {
// 	char *s1 = "ahammam";
// 	char s2[13];
// 	printf("%d",(int)ft_strlcat(s2,s1,13));
// }