# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzapata <mzapata@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/10/11 10:49:18 by mzapata           #+#    #+#              #
#    Updated: 2015/01/10 23:41:34 by mzapata          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SV = serveur
NAME_CL = client
NAME	= ft_retro
CXX		= g++
CFLAGS	= -Wall -Wextra -Werror
LDFLAGS	= -lncurses
SRC_DIR	= srcs
SRCS	= main.cpp Entity.cpp Enemy.cpp Bullet.cpp GameState.cpp Player.cpp
INC_DIR = includes
INFLAGS	= -I$(INC_DIR)
VPATH	= :$(SRC_DIR)
OBJ_DIR = objs
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

all: $(OBJ_DIR) $(NAME)
	@echo "Done."

$(NAME): $(OBJS)
	@echo "Linking binary..."
	@$(CXX) $^ $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Compiling $<."
	@$(CXX) $(CFLAGS) $(INFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "Deleting obj files."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Deleting binaries."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
