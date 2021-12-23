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
#include "printf/ft_printf.h"

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

void	ft_send_char(int iPid, char *byte)
{
	int		i;

	i = 0;
	while (byte[i])
	{
		if (byte[i] == '0')
			kill(iPid, SIGUSR1);
		else
			kill(iPid, SIGUSR2);
		i++;
		usleep(200);
	}
}

int	main(int argc, char *argv[])
{
	char	*byte;
	int		i;
	int		ipid;

	i = 0;
	byte = 0;
	ipid = ft_atoi(argv[1]);
	if (argc >= 3)
	{
		while (1)
		{
			byte = char_to_byte(argv[2][i]);
			ft_send_char(ipid, byte);
			free(byte);
			byte = 0;
			if (argv[2][i] == 0)
				break ;
			i++;
		}
	}
}
