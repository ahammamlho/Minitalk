/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:53:51 by lahammam          #+#    #+#             */
/*   Updated: 2021/12/21 12:53:53 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	ft_byte_to_char(char *byte)
{
	int		result;
	int		i;
	int		pwr;
	int		j;

	i = 0;
	result = 0;
	pwr = 1;
	j = 0;
	while (byte && byte[i])
	{
		while (j < 7 - i && ++j)
			pwr = pwr * 2;
		if (byte[i] == '1')
			result = result + pwr;
		i++;
		j = 0;
		pwr = 1;
	}
	return (result);
}

void	ft_cas_error(int *si_pid, int *nbr_bit, int pid)
{
	if (*si_pid == 0)
		*si_pid = pid;
	if (*si_pid != pid)
	{
		*nbr_bit = 0;
		*si_pid = pid;
	}
}

void	handler(int sig, siginfo_t *info, void *p)
{
	static int		nbr_bit = 0;
	static char		byte[8];
	static int		si_pid = 0;
	char			c;

	ft_cas_error(&si_pid, &nbr_bit, info->si_pid);
	p++;
	if (sig == SIGUSR1)
		byte[nbr_bit] = '0';
	else
		byte[nbr_bit] = '1';
	nbr_bit++;
	if (nbr_bit == 8)
	{
		nbr_bit = 0;
		c = ft_byte_to_char(byte);
		write(1, &c, 1);
	}
}

int	main(void)
{
	pid_t				ipid;
	struct sigaction	sa;

	ipid = getpid();
	ft_putstr("iPid : ");
	ft_putnbr(ipid);
	write(1, "\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
