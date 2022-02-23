# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/07 20:22:21 by aaljaber          #+#    #+#              #
#    Updated: 2021/11/07 20:22:36 by aaljaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c printnbr.c printunbr.c printxsc.c printptr.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

INCS = ft_printf.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

.c.o :
	${CC} ${CFLAGS} -I ${INCS} -c $< -o ${<:.c=.o}

${NAME} :   ${OBJS}
	ar rc ${NAME} ${OBJS}

all : ${NAME}

clean :
	${RM} ${OBJS} 
	
fclean :    clean
	${RM} ${NAME}

re : fclean all

.PHONY : all .c.o clean fclean re 
