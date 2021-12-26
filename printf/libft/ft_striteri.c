/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:33:14 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/08 12:55:19 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int		i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// void f(unsigned int index, char *c)
// {
// 	index++;
// 	*c += 1;
// }
// #include <stdio.h>
// int main()
// {
// 	char s[] = "test";
// 	ft_striteri(s, f);
// 	printf("%s\n", s);
// }