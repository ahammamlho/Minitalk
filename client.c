#include<stdio.h>
#include<signal.h>
#include <unistd.h>
#include <stdlib.h>
//#include "printf/ft_printf.h"
#include "./printf/libft/libft.h"


char *char_to_bin(char c)
{
	int i;
	char *result;
	int b;

	i = 7;
	result = malloc(sizeof(char) * 9);
	while (i >= 0 )
	{
		b = c & (1<<i);
		if (b > 0)
			result[7 - i] = '1';
		else
			result[7 -i] = '0';
		i--;
	}
   return (result);
}


void send_char(int iPid,char *bin)
{
	int i;

	i = 0;
	while (bin[i])
	{
		sleep(1);
		if (bin[i] == '0')
			kill(iPid, SIGUSR1);
		else
			kill(iPid, SIGUSR2);
		i++;
	}
}
int main(int argc, char *argv[])
{
	char *bin;
	int i;

	
	i = 0;
	printf("%s", argv[1]);
	while(argv[2][i])
	{
		bin = char_to_bin(argv[2][i]);
		ft_send_char(atoi(argv[1]), bin);
		i++;
	}
	
}