/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:13:26 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/08 10:06:41 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*temp;
	int		i;
	char	*result;

	i = 0;
	temp = (char *)str;
	result = 0;
	if (c == '\0')
		return (&temp[ft_strlen(str)]);
	while (temp[i] != '\0')
	{
		if (temp[i] == (char )c)
			result = &temp[i];
		i++;
	}
	return (result);
}

// int main()
// {
// 	printf("%s",ft_strrchr("ahammamt",'\0'));
// }