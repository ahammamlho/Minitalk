/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:21:38 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/05 09:36:16 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*result;
	unsigned int		i;

	i = 0;
	result = (char *)malloc(ft_strlen(s) + 1);
	if (!result)
		return (0);
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// char f(unsigned int i,char c)
// {
// 	char ch;
// 	i++;
// 	ch = c + 1;
// 	return ch;
// }

// int main()
// {
// 	printf("%s",ft_strmapi("ahammam", f));
// }