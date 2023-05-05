# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 15:01:42 by ratinhosujo       #+#    #+#              #
#    Updated: 2023/05/05 15:17:26 by ratinhosujo      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GPP = c++

NAME = webserv

SRCS = CPU_Work/utils.cpp \
	   CPU_Work/starting.cpp \
	   CPU_Work/WebServer.cpp \
	   CPU_Work/SetSockAddr.cpp \
	   CPU_Work/error_handler.cpp \
	   IO_Work/bind_nd_listen.cpp \
	   IO_Work/connect_nd_send.cpp \
	   main.cpp

OBJS = $(SRCS: .cpp = .o)

CPPFLAGS = -g -Wall -Wextra -Werror -fsanitize=address -std=c++98

all :	$(NAME)

$(NAME): $(OBJS)
	@$(GPP) $(CPPFLAGS) -o $(NAME) $(OBJS)
	@echo -e "\033[102m\033[1m WebServer created. \033[0m"

clean :
	@rm -rf *.o

fclean :	clean
	@rm -rf $(NAME)
	@echo -e "\033[101m\033[1m WebServer deleted. \033[0m"

re :	fclean all

.PHONY :	all clean fclean re bonus