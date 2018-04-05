#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/20 20:11:43 by tmaslyan          #+#    #+#              #
#    Updated: 2018/03/20 20:11:44 by tmaslyan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

HEAD = libft.h
SOURCES	=	ft_lstdel.c\
		ft_putchar.c\
		ft_strdel.c\
		ft_strnew.c\
		ft_lstdelone.c\
		ft_putchar_fd.c\
		ft_strdup.c\
		ft_strnstr.c\
		ft_atoi.c\
		ft_lstiter.c\
		ft_putendl.c\
		ft_strequ.c\
		ft_strrchr.c\
		ft_bzero.c\
		ft_lstmap.c\
		ft_putendl_fd.c	\
		ft_striter.c\
		ft_strrev.c\
		ft_factorial.c\
		ft_lstnew.c\
		ft_putnbr.c\
		ft_striteri.c\
		ft_strsplit.c\
		ft_intsqrt.c\
		ft_memalloc.c\
		ft_putnbr_fd.c\
		ft_strjoin.c\
		ft_strstr.c\
		ft_isalnum.c\
		ft_memccpy.c\
		ft_putstr.c\
		ft_strlcat.c\
		ft_strsub.c\
		ft_isalpha.c\
		ft_memchr.c\
		ft_putstr_fd.c\
		ft_strlen.c\
		ft_strtrim.c\
		ft_isascii.c\
		ft_memcmp.c\
		ft_simple_pow.c\
		ft_strmap.c\
		ft_tolower.c\
		ft_isdigit.c\
		ft_memcpy.c\
		ft_strcat.c\
		ft_strmapi.c\
		ft_toupper.c\
		ft_isprime.c\
		ft_memdel.c\
		ft_strchr.c\
		ft_strncat.c\
		ft_isprint.c\
		ft_memmove.c\
		ft_strclr.c\
		ft_strncmp.c\
		ft_itoa.c\
		ft_memset.c\
		ft_strcmp.c\
		ft_strncpy.c\
		ft_lstadd.c\
		ft_nextprime.c\
		ft_strcpy.c\
		ft_strnequ.c\
		ft_sort_list.c

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
OPTION = -c -I $(HEAD)
OBJ =		ft_lstdel.o\
		ft_putchar.o\
		ft_strdel.o\
		ft_strnew.o\
		ft_lstdelone.o\
		ft_putchar_fd.o\
		ft_strdup.o\
		ft_strnstr.o\
		ft_atoi.o\
		ft_lstiter.o\
		ft_putendl.o\
		ft_strequ.o\
		ft_strrchr.o\
		ft_bzero.o\
		ft_lstmap.o\
		ft_putendl_fd.o\
		ft_striter.o\
		ft_strrev.o\
		ft_factorial.o\
		ft_lstnew.o\
		ft_putnbr.o\
		ft_striteri.o\
		ft_strsplit.o\
		ft_intsqrt.o\
		ft_memalloc.o\
		ft_putnbr_fd.o\
		ft_strjoin.o\
		ft_strstr.o\
		ft_isalnum.o\
		ft_memccpy.o\
		ft_putstr.o\
		ft_strlcat.o\
		ft_strsub.o\
		ft_isalpha.o\
		ft_memchr.o\
		ft_putstr_fd.o\
		ft_strlen.o\
		ft_strtrim.o\
		ft_isascii.o\
		ft_memcmp.o\
		ft_simple_pow.o\
		ft_strmap.o\
		ft_tolower.o\
		ft_isdigit.o\
		ft_memcpy.o\
		ft_strcat.o\
		ft_strmapi.o\
		ft_toupper.o\
		ft_isprime.o\
		ft_memdel.o\
		ft_strchr.o\
		ft_strncat.o\
		ft_isprint.o\
		ft_memmove.o\
		ft_strclr.o\
		ft_strncmp.o\
		ft_itoa.o\
		ft_memset.o\
		ft_strcmp.o\
		ft_strncpy.o\
		ft_lstadd.o\
		ft_nextprime.o\
		ft_strcpy.o\
		ft_strnequ.o\
		ft_sort_list.o


all: $(NAME)
$(NAME):
	gcc $(FLAGS) $(OPTION) $(SOURCES)
	ar rc $(NAME) $(OBJ)
clean :
	/bin/rm -f $(OBJ)
fclean : clean
	/bin/rm -f $(NAME)
re : fclean all