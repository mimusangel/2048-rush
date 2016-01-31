# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/30 10:06:49 by mgallo            #+#    #+#              #
#    Updated: 2016/01/30 15:36:20 by mgallo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY = all clean fclean re

NAME = game_2048
FILES = main.c grid.c scene.c control.c control_game.c color.c utils.c check.c
SRC_FOLDER = sources/
OBJ_FOLDER = build/
SRCS = $(addprefix $(SRC_FOLDER),$(FILES))
OBJS = $(addprefix $(OBJ_FOLDER),$(FILES:.c=.o))
CFLAG = -Wall -Wextra -Werror
INCLUDES = -I libft/
LIBS = -L libft/ -lft -lncurses

all: $(NAME)

build:
	mkdir -p $(OBJ_FOLDER)
	make -C libft/ re

$(OBJS): $(OBJ_FOLDER)%.o : $(SRC_FOLDER)%.c
	gcc $(CFLAG) $(INCLUDES) -c $< -o $@

$(NAME): build $(OBJS)
	gcc -o $(NAME) $(OBJS) $(INCLUDES) $(LIBS)

clean:
	make -C libft/ clean
	rm -f $(OBJS)
	rm -rf $(OBJ_FOLDER)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
