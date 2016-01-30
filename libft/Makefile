# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgallo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 16:08:01 by mgallo            #+#    #+#              #
#    Updated: 2015/12/20 21:31:33 by mgallo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY = all clean fclean re

NAME = libft.a
SRCS = ft_atoi.c ft_memalloc.c ft_putchar.c ft_strcat.c ft_striter.c\
	   ft_strncmp.c ft_strsub.c ft_bzero.c ft_memccpy.c ft_putchar_fd.c\
	   ft_strchr.c ft_striteri.c ft_strncpy.c ft_strtrim.c ft_isalnum.c\
	   ft_memchr.c ft_putendl.c ft_strclr.c ft_strjoin.c ft_strnequ.c\
	   ft_tolower.c ft_isalpha.c ft_memcmp.c ft_putendl_fd.c ft_strcmp.c\
	   ft_strlcat.c ft_strnew.c ft_toupper.c ft_isascii.c ft_memcpy.c\
	   ft_putnbr.c ft_strcpy.c ft_strlen.c ft_strnstr.c ft_isdigit.c\
	   ft_memdel.c ft_putnbr_fd.c ft_strdel.c ft_strmap.c ft_strrchr.c\
	   ft_isprint.c ft_memmove.c ft_putstr.c ft_strdup.c ft_strmapi.c\
	   ft_strsplit.c ft_itoa.c ft_memset.c ft_putstr_fd.c ft_strequ.c\
	   ft_strncat.c ft_strstr.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c\
	   ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_arraylen.c ft_arraytlen.c\
	   ft_arraytostr.c ft_putarray_fd.c ft_putarray.c ft_memdup.c\
	   ft_strclen.c ft_lstappend.c ft_lstlen.c ft_lstaddto.c ft_lstremove.c\
	   ft_lstget.c ft_arraydel.c get_next_line.c
OBJS = $(SRCS:.c=.o)
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
