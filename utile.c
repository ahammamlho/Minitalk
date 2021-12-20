

#include "mnitalk.h"


int ft_power(int nbr, int pw)
{
    int result;
    int i;

    i = 1;
    result = nbr;
	if (pw == 0)
		return (1);
    while (i < pw)
    {
        result = result * nbr;
		i++;
    }
    return (result);

}

char ft_bin_to_char(char *bin)
{
    int result;
    int i;

    i = 0;
    result = 0;
    while (bin && bin[i])
    {
		if (bin[i] == '1')
        	result = result + ft_power(2, 7 - i);
        i++;
		
    }
    return (result);
}

char *ft_add__char(char *str, char c)
{
	char *res;
	int i;

	res = 0;
	i = 0;
	if (!str)
		res = (char *)ft_calloc(sizeof(char), 2);
	else
		res = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 2);
	while (str && str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = c;
	if (str)
		free(str);
	return (res);
}
