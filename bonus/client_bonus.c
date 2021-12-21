/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:53:42 by lahammam          #+#    #+#             */
/*   Updated: 2021/12/21 12:53:45 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<signal.h>
#include <unistd.h>
#include "../printf/ft_printf.h"

char	*char_to_byte(char c)
{
	int		i;
	char	*result;
	int		b;

	i = 7;
	result = ft_calloc(9, sizeof(char));
	while (i >= 0)
	{
		b = c & (1 << i);
		if (b > 0)
			result[7 - i] = '1';
		else
			result[7 - i] = '0';
		i--;
	}
	return (result);
}

int g_pass = 0;

void	ft_send_char(int iPid, char *byte)
{
	int		i;

	i = 0;
	while (byte[i])
	{
		while (g_pass)
			;
		g_pass = 1;
		if (byte[i] == '0')
			kill(iPid, SIGUSR1);
		else
			kill(iPid, SIGUSR2);
		i++;
		sleep(20);
	}
}

void handler(int sig)
{
	g_pass = 0;
}

int	main(int argc, char *argv[])
{
	char	*byte;
	int		i;
	struct sigaction	sa;

	i = 0;
	byte = 0;
	signal(SIGUSR1, handler);
	
	if (argc >= 3)
	{
		while (ft_strlen(argv[2]) >= i)
		{
			byte = char_to_byte(argv[2][i]);
			ft_send_char(ft_atoi(argv[1]), byte);
			free(byte);
			byte = 0;
			i++;	
		}
	}
	exit(0);
}
