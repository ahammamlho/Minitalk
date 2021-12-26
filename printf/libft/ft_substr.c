/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:24:12 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/21 10:36:41 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*result;
	unsigned int		i;

	i = 0;
	if (ft_strlen(s) < start || len == 0)
		return ((char *)ft_calloc(1, 1));
	else if (ft_strlen(s) - start < len)
		result = (char *)ft_calloc(ft_strlen(s) - start + 1, 1);
	else
		result = (char *)ft_calloc(len + 1, 1);
	if (!result)
		return (0);
	while (s && s[i + start] != '\0' && i < len)
	{
		result[i] = s[i + start];
		i++;
	}
	if (len != 0)
		result[i] = '\0';
	return (result);
}

// int main()
// {
// 	printf ("-->|%s|\n",ft_substr("ahammam", 2, 0));
// }
