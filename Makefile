CC = cc 

CFLAGS = -Wall -Werror -Wextra -I.

INC = minitalk.h

SRCS_SERVEUR =	server/server.c	\
				server/ft_bzero.c

SRCS_CLIENT =	client_funct/client.c	\
				client_funct/ft_atoi.c

OBJS_SERVEUR = ${SRCS_SERVEUR:.c=.o}
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}

all: serveur client

serveur: $(OBJS_SERVEUR)
	cc ${CFLAGS} $(OBJS_SERVEUR) lib/libftprintf.a -o serveur  

client : $(OBJS_CLIENT)
	cc ${CFLAGS} $(OBJS_CLIENT) lib/libftprintf.a -o client 

clean:
		rm -f server/*.o
		rm -f client_funct/*.o

fclean: clean
		rm client serveur 

re: fclean all

.PHONY: re clean fclean