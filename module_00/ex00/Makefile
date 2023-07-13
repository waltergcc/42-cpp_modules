# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 17:07:34 by wcorrea-          #+#    #+#              #
#    Updated: 2023/07/13 16:29:15 by wcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRC = megaphone.cpp

CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME):
		${CC} ${CPPFLAGS} ${SRC} -o ${NAME}

all:	${NAME}

clean:
		${RM} ${NAME}

re: clean all

.PHONY: all clean re