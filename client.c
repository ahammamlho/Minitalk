



#include "mnitalk.h"


char *char_to_bin(char c)
{
	int i;
	char *result;
	int b;

	i = 7;
	result = ft_calloc(sizeof(char), 9);
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

void ft_send_char(int iPid,char *bin)
{
	int i;

	i = 0;
	while (bin[i])
	{
		usleep(1000);
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
	int iPid;

	
	i = 0;
	bin = 0;
	iPid = ft_atoi(argv[1]);
	while(1)
	{
		bin = char_to_bin(argv[2][i]);
		ft_send_char( iPid, bin );
		free(bin);
		if (argv[2][i] == 0)
			break;
		i++;
	}

	
}