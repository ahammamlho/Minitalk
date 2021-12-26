/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:12:35 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/06 14:23:53 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)&s1[i]);
	while (s1[i] != '\0')
	{
		while (s2 && s1[i + j] == s2[j] && i + j < n)
		{
			j++;
			if (s2[j] == '\0')
				return ((char *)&s1[i]);
		}
		i++;
		j = 0;
	}
	return (0);
}

// int main()
// {
// 	printf("%s",ft_strnstr("123456789","34",7));
// }