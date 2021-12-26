/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:11:13 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/08 10:31:38 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)str;
	if ((char )c == '\0')
		return (&temp[ft_strlen(str)]);
	while (temp[i] != '\0')
	{
		if (temp[i] == (char )c)
			return (&temp[i]);
		i++;
	}
	return (0);
}
// #include <string.h> 
// int main()
// {
// 	printf("%s",ft_strchr( 0,'\0'));
// }