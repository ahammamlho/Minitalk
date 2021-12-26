/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:56:45 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/06 17:19:34 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isexist(char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_first(char *src, char *set)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (!ft_isexist(set, src[i]))
			return (i);
		i++;
	}
	return (0);
}

static int	ft_end(char *src, char *set)
{
	int	len;

	len = ft_strlen((const char *)src);
	while (len > 0)
	{
		if (!ft_isexist(set, src[len - 1]))
			return (len);
		len--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	start = ft_first((char *)s1, (char *)set);
	end = ft_end((char *)s1, (char *)set);
	return (ft_substr(s1, start, end - start));
}

// int main()
// {
// 	printf("%s\n", ft_strtrim("lorem \n ipsum \t dolor \n sit \t amet", " "));
// }