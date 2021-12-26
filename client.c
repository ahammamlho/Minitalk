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

#include "minitalk.h"

void	ft_send_char(int iPid, char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 7;
		while (j >= 0)
		{
			if ((str[i] & (1 << j)) > 0)
				kill(iPid, SIGUSR2);
			else
				kill(iPid, SIGUSR1);
			usleep(1000);
			j--;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		ipid;

	if (argc >= 3)
	{
		ipid = ft_atoi(argv[1]);
		ft_send_char(ipid, argv[2]);
	}
}
