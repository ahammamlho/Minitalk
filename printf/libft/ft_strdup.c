/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:54:48 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/03 15:44:19 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*result;
	char	*t_src;

	i = 0;
	t_src = (char *)src;
	result = (char *) malloc(ft_strlen(src) + 1);
	if (!result)
		return (0);
	while (t_src[i])
	{
		result[i] = t_src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

// int main()
// {
// 	printf("%s",ft_strdup("ahammam"));
// }