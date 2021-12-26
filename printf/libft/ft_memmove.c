/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:10:30 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/07 17:22:31 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*t_dest;
	unsigned char	*t_src;

	i = -1;
	if (!dest && !src)
		return (0);
	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	if (t_src < t_dest && t_dest < t_src + n)
		while (++i < n)
			t_dest[n - 1 - i] = t_src[n - 1 - i];
	else
		while (++i < n)
			t_dest[i] = t_src[i];
	return ((void *)dest);
}

// #include <string.h>

// int	main () {
// 	char *dest;
// 	char *dest1;
// 	char src[] = "lorem ipsum dolor sit amet";
// 	  char src1[] = "lorem ipsum dolor sit amet";
// 	dest = src +1;
// 	dest1 = src1 +1;
//  //  const char src[]  = "new++++++"; 
//   printf(" %s\n",dest);
//   memmove(src, dest, 8);

//   ft_memmove(src1, dest1, 8);

// 	  printf(" %s\n",src);
// 	  printf(" %s\n",src1);
// // 	int i = 0;
// // 	while ( ++i < 10)
// // 		printf("%d - ", i);
// //    return(0);
// }
