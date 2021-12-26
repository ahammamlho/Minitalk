/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:10:53 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/24 11:53:19 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	unsigned int	i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)ptr;
	while (i < n)
	{
		*(temp + i) = x;
		i++;
	}
	return (ptr);
}

// int main()
// {
// 	char str[] = "ahammam";
// 	printf("%s",(char) *ft_memset(str, 65,6));
// }
