/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 11:26:28 by lahammam          #+#    #+#             */
/*   Updated: 2021/12/26 11:26:30 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_isspace(char c)
{
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long int		result;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1 * sign;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return ((int )(sign * result));
}

void	ft_putstr(char *s)
{
	int		i;

	i = 0;
	while (*(s + i) != '\0')
	{
		write(1, (s + i), 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	char	a;

	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 10 && n >= 0)
	{
		a = n + 48;
		write(1, &a, 1);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-1 * n);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
