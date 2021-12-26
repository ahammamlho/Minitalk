GCC = cc
AR = ar rc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf

%.o : %.c
	   ${GCC} ${CFLAGS} -c $< -o $@

all : 
		${MAKE} -C printf
		${GCC} ${CFLAGS} client.c ./printf/libftprintf.a -o client
		${GCC} ${CFLAGS} server.c ./printf/libftprintf.a -o server

bonus: 
		${MAKE} -C printf
		${GCC} ${CFLAGS} bonus/client_bonus.c ./printf/libftprintf.a -o client_bonus
		${GCC} ${CFLAGS} bonus/server_bonus.c ./printf/libftprintf.a -o server_bonus

clean:
		${RM} printf/*.o printf/libft/*.o

fclean: clean
		${RM}  printf/*.a printf/libft/*.a server client_bonus server_bonus

re:	fclean all

.PHONY: all clean fclean re bonus