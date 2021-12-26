/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:11:53 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/07 12:09:45 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (size != 0 && src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	if (size != 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}

// int main()
// {
// 	char des1[100];
// 	printf("%d\n",(int)ft_strlcpy(des1,"lorem ipsum dolor sit amet",0));
// 	printf("%s",des1);
// }