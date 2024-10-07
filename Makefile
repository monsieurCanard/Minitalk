CC = gcc 

CFLAGS = -Wall -Werror -Wextra -I.

INC 		= 	minitalk.h

SRCS_SERVEUR		= 	server/server.c		\
						server/ft_bzero.c

SRCS_CLIENT			= 	client/ft_atoi.c		\
						client/client.c

OBJS_SERVEUR = ${SRCS_SERVEUR:.c=.o}

OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}

all: serveur client

serveur: server/server.c
	cc ${CFLAGS} ${SRCS_SERVEUR} lib/libftprintf.a -o serveur  

client : client/client.c
	cc ${CFLAGS} ${SRCS_CLIENT} lib/libftprintf.a -o client 

clean:	
		rm -f server/*.o
		rm -f client/*.o

fclean:	clean
		rm client serveur 

re:	fclean all

.PHONY: re clean fclean