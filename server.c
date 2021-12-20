

#include "mnitalk.h"


char *result = 0;

void handle(int sig)
{
    static int nbr_bit = 0;
    static char bit[8];
    char c;
	if (sig == SIGUSR1)
       bit[nbr_bit] = '0';
    else
        bit[nbr_bit] = '1';
    nbr_bit++;
 
    if (nbr_bit == 8)
    {
        nbr_bit = 0;
        c = ft_bin_to_char(bit);
        result = ft_add__char(result , c);
        if (c == 0)
        {
            ft_printf("%s", result);
            ft_putchar_fd('\n', 1);
            ft_bzero(result, ft_strlen(result));
            free(result);
            result = 0;
        }
        ft_bzero(bit, 8);
    }
}

int main()
{
    pid_t iPid = getpid(); /* Process gets its id.*/
    ft_printf("iPid : %d", iPid);
    ft_putchar_fd('\n', 1);
    struct sigaction sa;
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = &handle;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    
    while (1)
        sleep(1);
	return (0);
}