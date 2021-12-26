# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lahammam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 11:26:46 by lahammam          #+#    #+#              #
#    Updated: 2021/12/26 11:26:50 by lahammam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf

${NAME} :
		${CC} ${CFLAGS} client.c utils.c -o client
		${CC} ${CFLAGS} server.c utils.c -o server
all : ${NAME}

bonus: 
		${CC} ${CFLAGS} client_bonus.c utils.c -o client_bonus
		${CC} ${CFLAGS} server_bonus.c utils.c -o server_bonus

clean:
		${RM} server client server_bonus client_bonus

fclean: clean

re:	fclean all

.PHONY: all clean fclean re bonus
