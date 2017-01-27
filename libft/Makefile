# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hazzout <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 18:14:56 by hazzout           #+#    #+#              #
#    Updated: 2016/11/27 18:00:58 by hazzout          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC= gcc 
SRC= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c       \
	 ft_isdigit.c ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c  \
	 ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memcmp.c ft_memcpy.c      \
	 ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
	 ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c \
	 ft_strcpy.c ft_strdup.c ft_strlen.c ft_strncat.c ft_strncpy.c     \
	 ft_tolower.c ft_toupper.c ft_strchr.c ft_memchr.c ft_strcmp.c     \
	 ft_strncmp.c ft_strstr.c ft_strequ.c ft_strnequ.c ft_strdel.c     \
	 ft_strnew.c ft_strclr.c ft_strjoin.c ft_strtrim.c ft_strnstr.c    \
	 ft_putendl_fd.c ft_putendl.c ft_strsplit.c ft_strsub.c            \
	 ft_strrchr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c  \
	 ft_strlcat.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c   \
	 ft_lstiter.c ft_lstmap.c ft_lstnbrelems.c ft_lstlastelem.c        \
     ft_lstadd_last.c 
OBJ= $(SRC:.c=.o)
HDIR= -I .
FLAG= -Wall -Wextra -Werror
RM= rm -f
NAME=libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(SRC)
	$(GCC) -c $(FLAG) $(SRC) $(HDIR)

norm:
	norminette -R CheckForbiddenSourceHeader $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re : fclean all
