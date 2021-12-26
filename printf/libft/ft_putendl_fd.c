/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:51:48 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/06 16:12:38 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;

	i = 0;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
// int main()
// {
// 	ft_putendl_fd("ahammam", 1);
// }