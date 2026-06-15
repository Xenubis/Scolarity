# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/09 17:23:37 by mvignes           #+#    #+#              #
#    Updated: 2026/04/22 09:45:06 by mvignes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_is_space.c\
		ft_strlen.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strncmp.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strnstr.c\
		ft_atoi.c\
		ft_atol.c\
		ft_atoi_base.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_free_tab.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lst_create_and_addback.c\
		ft_lst_sort.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_print_char.c\
		ft_printf.c\
		ft_print_int.c\
		ft_size.c\
		get_next_line.c\
		get_next_line_utils.c\

SRCS_BONUS=\

NAME	= libft.a
INC		= libft.h
CC		= cc -Wall -Wextra -Werror -g #-fsanitize=address,leak,undefined

MAKEFLAGS	+= --no-print-directory

RM		= rm -f
OBJS	= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

%.o: %.c $(INC)
	@$(CC) -I $(INC) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJS) $(INC)
	@ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJS_BONUS)
	@ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
