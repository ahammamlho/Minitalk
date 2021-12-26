/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:10:15 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/07 17:56:07 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*t_dest;
	unsigned char	*t_src;

	i = 0;
	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	if (!t_dest && !t_src)
		return (0);
	while (i < n)
	{
		t_dest[i] = t_src[i];
		i++;
	}
	return (dest);
}

// int main()
// {
// 	 char src[] = "test basic du memcpy !";
//         char buff1[22];
// 	printf("-->%s", (char *)ft_memcpy(s1,s2,5));
// }