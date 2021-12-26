/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:12:20 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/08 10:09:45 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*t_str1;
	unsigned char	*t_str2;

	t_str1 = (unsigned char *)str1;
	t_str2 = (unsigned char *)str2;
	i = 0;
	if (n == 0)
		return (0);
	while (t_str1[i] != '\0' && t_str1[i] == t_str2[i] && i < n - 1)
		i++;
	return (t_str1[i] - t_str2[i]);
}

// int main()
// {
// 	printf("->%d\n", ft_strncmp("test\200","test\0", 6));
// 	printf("->%d\n", strncmp("test\200","test\0", 6));
// 	printf("%d" , '\200' - '\0');
// }