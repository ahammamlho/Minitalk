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

int	g_pass = 0;

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
			while (g_pass)
				pause();
			usleep(600);
			g_pass = 1;
			if ((str[i] & (1 << j)) > 0)
				kill(iPid, SIGUSR2);
			else
				kill(iPid, SIGUSR1);
			j--;
		}
		i++;
	}
}

void	handler(int sig)
{
	sig++;
	g_pass = 0;
}

int	main(int argc, char *argv[])
{
	signal(SIGUSR1, handler);
	if (argc >= 3)
		ft_send_char(ft_atoi(argv[1]), argv[2]);
	exit(0);
}
