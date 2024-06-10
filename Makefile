# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/08 20:43:53 by olaaroub          #+#    #+#              #
#    Updated: 2024/06/10 19:57:09 by olaaroub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC = cc
CFLAGS = -Wall -Wextra -Werror
#  CFLAGS += -fsanitize=address -g3

CLIENT_SRC = client.c 
SERVER_SRC = server.c
SERVER_BONUS_SRC =bonus/server_bonus.c
CLIENT_BONUS_SRC = bonus/client_bonus.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)

CLIENT_NAME = client
SERVER_NAME = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
LIB = libft/libft.a

all:  $(SERVER_NAME) $(CLIENT_NAME)

$(CLIENT_NAME): $(CLIENT_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIB)  -o $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJ)  $(LIB)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIB)  -o $(SERVER_NAME)

$(LIB):
	$(MAKE) -C libft
	
bonus: $(SERVER_BONUS) $(CLIENT_BONUS) $(LIB)

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) $(LIB) -o $(CLIENT_BONUS)

$(SERVER_BONUS): $(SERVER_BONUS_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) $(LIB) -o $(SERVER_BONUS)

clean:
	@rm -rf $(CLIENT_OBJ) $(SERVER_OBJ) $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ)
	$(MAKE) clean -C libft

fclean: clean
	@rm -rf $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_BONUS) $(SERVER_BONUS)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: clean fclean re all bonus
.SECONDARY: $(CLIENT_OBJ) $(SERVER_OBJ)
