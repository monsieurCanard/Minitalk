CC = cc

CFLAGS = -Wall -Werror -Wextra

INC 		= 	minitalk.h

SRCS_SERVEUR		= 	serveur.c		\
						ft_bzero.c 		\

SRCS_CLIENT			= 	ft_atoi.c		\
						client.c		\

OBJS_SERVEUR = ${SRCS_SERVEUR:.c=.o}

OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}

all: serveur client

serveur: serveur.c
	cc ${CFLAGS} ${SRCS_SERVEUR} libftprintf.a -o serveur  

client : client.c
	cc ${CFLAGS} ${SRCS_CLIENT} libftprintf.a -o client 

clean:	
		rm -f *.o

fclean:	clean
		rm -f client serveur 

re:	fclean all

.PHONY: re clean fclean