# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmoran <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016 10 05 20:17:32 by pmoran            #+#    #+#              #
#    Updated: 2016/11/28 00:29:37 by pmoran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	fillit

CHECK = -Wall -Wextra -Werror

INCLUDES = -c -I libft.h

SRC =	freebird.c full.c preadtolist.c ft_lstcount.c ft_lstreverse.c\
		valid_and_crop.c check_and_pass_tetras.c pread.c ft_atoi.c ft_bzero.c\
		ft_lstcount.c ft_lstreverse.c ft_isalnum.c  ft_isalpha.c ft_isascii.c\
		ft_isdigit.c  ft_isprint.c ft_memalloc.c  ft_memccpy.c  ft_memchr.c\
		ft_memcmp.c ft_memcpy.c  ft_memdel.c  ft_memmove.c  ft_memset.c\
		ft_putchar.c  ft_putchar_fd.c  ft_putendl.c  ft_putendl_fd.c\
		ft_putnbr.c  ft_putnbr_fd.c  ft_putstr.c  ft_putstr_fd.c  ft_strcat.c\
		connect_count.c ft_strclr.c  ft_strcmp.c  ft_strcpy.c  ft_strdel.c\
		ft_strdup.c  ft_strequ.c  ft_striter.c  ft_striteri.c\
		ft_strlcat.c  ft_strlen.c  ft_strmap.c  ft_strmapi.c\
		ft_strncat.c  ft_strncmp.c  ft_strncpy.c  ft_strnequ.c\
		nineteen.c ft_strnew.c  ft_strstr.c  ft_strsub.c  ft_tolower.c\
		ft_toupper.c ft_strjoin.c ft_strsplit.c ft_strtrim.c ft_itoa.c\
		ft_strchr.c ft_strrchr.c ft_strnstr.c ft_lstnew.c ft_lstdelone.c\
		ft_lstadd.c ft_lstdel.c ft_lstiter.c ft_lstmap.c

OBJ =	freebird.o full.o preadtolist.o ft_lstcount.o ft_lstreverse.o\
		valid_and_crop.o check_and_pass_tetras.o pread.o ft_atoi.o ft_bzero.o\
		ft_lstcount.o ft_lstreverse.o ft_isalnum.o ft_isalpha.o ft_isascii.o\
		ft_isdigit.o ft_isprint.o ft_memalloc.o \
		ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o\
		ft_memdel.o ft_memmove.o ft_memset.o ft_putchar.o \
		ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o\
		ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o ft_strcat.o\
		connect_count.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o\
		ft_strdup.o ft_strequ.o ft_striter.o ft_striteri.o\
		ft_strlcat.o ft_strlen.o ft_strmap.o ft_strmapi.o\
		ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnequ.o\
		nineteen.o ft_strnew.o ft_strstr.o ft_strsub.o ft_tolower.o\
		ft_toupper.o ft_strjoin.o ft_strsplit.o ft_strtrim.o ft_itoa.o\
		ft_strchr.o ft_strrchr.o ft_strnstr.o ft_lstnew.o ft_lstdelone.o\
		ft_lstadd.o ft_lstdel.o ft_lstiter.o ft_lstmap.o

all: $(NAME)

$(NAME):
	gcc $(SRC) $(INCLUDES)
	ar rc libft.a $(OBJ) 
	gcc pread.c libft.a -o $(NAME)

clean:
	rm -f $(OBJ)
fclean:
	rm -f $(OBJ) fillit libft.a

re: fclean all
