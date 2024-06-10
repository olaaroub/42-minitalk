# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/08 20:43:53 by olaaroub          #+#    #+#              #
#    Updated: 2024/06/10 11:54:07 by olaaroub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC = cc
#CFLAGS = -Wall -Wextra -Werror
 CFLAGS += -fsanitize=address -g3

CLIENT_SRC = client.c 
SERVER_SRC = server.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_NAME = client
SERVER_NAME = server
LIB = libft/libft.a

all:  $(SERVER_NAME) $(CLIENT_NAME)

$(CLIENT_NAME): $(CLIENT_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIB)  -o $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJ)  $(LIB)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIB)  -o $(SERVER_NAME)

$(LIB):
	$(MAKE) -C libft

clean:
	@rm -rf $(CLIENT_OBJ) $(SERVER_OBJ)
	$(MAKE) clean -C libft

fclean:
	@rm -rf $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_OBJ) $(SERVER_OBJ)
	$(MAKE) fclean -C libft

re: fclean mandatory

.PHONY: clean fclean re mandatory bonus
.SECONDARY: $(CLIENT_OBJ) $(SERVER_OBJ)
