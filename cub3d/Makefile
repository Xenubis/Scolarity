#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/22 14:39:19 by mvignes           #+#    #+#              #
#    Updated: 2026/04/10 16:05:55 by mmusquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#================================================#
#                 _       _     _           	||
#                (_)     | |   | |          	||
#__   ____ _ _ __ _  __ _| |__ | | ___  ___ 	||
#\ \ / / _` | '__| |/ _` | '_ \| |/ _ \/ __|	||
# \ V / (_| | |  | | (_| | |_) | |  __/\__ \	||
#  \_/ \__,_|_|  |_|\__,_|_.__/|_|\___||___/	||
#================================================#

NAME		= cub3D
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g3
VALGRIND	= valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes
RM			= rm -f
MLX_DIR		= ./minilibx-linux
MLX_FLAGS	= -L./minilibx-linux -lmlx -lXext -lX11

MAKEFLAGS	+= --no-print-directory

RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENTA		= \033[0;35m
CYAN		= \033[0;36m
GRAS		= \033[1m
RESET		= \033[0m

SRCS_DIR	= srcs
OBJS_DIR	= .objects

SRCS	= \
		srcs/libft/ft_isalpha.c\
		srcs/libft/ft_isdigit.c\
		srcs/libft/ft_isalnum.c\
		srcs/libft/ft_isascii.c\
		srcs/libft/ft_isprint.c\
		srcs/libft/ft_is_space.c\
		srcs/libft/ft_strlen.c\
		srcs/libft/ft_memset.c\
		srcs/libft/ft_bzero.c\
		srcs/libft/ft_memcpy.c\
		srcs/libft/ft_memmove.c\
		srcs/libft/ft_strlcpy.c\
		srcs/libft/ft_strlcat.c\
		srcs/libft/ft_toupper.c\
		srcs/libft/ft_tolower.c\
		srcs/libft/ft_strchr.c\
		srcs/libft/ft_strrchr.c\
		srcs/libft/ft_strncmp.c\
		srcs/libft/ft_memchr.c\
		srcs/libft/ft_memcmp.c\
		srcs/libft/ft_strnstr.c\
		srcs/libft/ft_atoi.c\
		srcs/libft/ft_atol.c\
		srcs/libft/ft_atoi_base.c\
		srcs/libft/ft_calloc.c\
		srcs/libft/ft_strdup.c\
		srcs/libft/ft_free_tab.c\
		srcs/libft/ft_substr.c\
		srcs/libft/ft_strjoin.c\
		srcs/libft/ft_strtrim.c\
		srcs/libft/ft_split.c\
		srcs/libft/ft_itoa.c\
		srcs/libft/ft_strmapi.c\
		srcs/libft/ft_striteri.c\
		srcs/libft/ft_putchar_fd.c\
		srcs/libft/ft_putstr_fd.c\
		srcs/libft/ft_putendl_fd.c\
		srcs/libft/ft_putnbr_fd.c\
		srcs/libft/ft_lstnew.c\
		srcs/libft/ft_lstadd_front.c\
		srcs/libft/ft_lstsize.c\
		srcs/libft/ft_lstlast.c\
		srcs/libft/ft_lstadd_back.c\
		srcs/libft/ft_lstdelone.c\
		srcs/libft/ft_lstclear.c\
		srcs/libft/ft_lst_create_and_addback.c\
		srcs/libft/ft_lst_sort.c\
		srcs/libft/ft_lstiter.c\
		srcs/libft/ft_lstmap.c\
		srcs/libft/ft_print_char.c\
		srcs/libft/ft_printf.c\
		srcs/libft/ft_print_int.c\
		srcs/libft/ft_size.c\
		srcs/libft/get_next_line.c\
		srcs/libft/get_next_line_utils.c\
		\
		srcs/main.c\
		\
		srcs/parser/parser_checker.c\
		srcs/parser/parser_dispatch.c\
		srcs/parser/parser_flood.c\
		srcs/parser/parser_header_utils.c\
		srcs/parser/parser_header.c\
		srcs/parser/parser_map.c\
		srcs/parser/parser_utils.c\
		srcs/parser/parser_validation_utils.c\
		srcs/parser/parser_validation.c\
		srcs/parser/parser.c\
		\
		srcs/exec/check_wall.c\
		srcs/exec/color.c\
		srcs/exec/dda_utils.c\
		srcs/exec/dda.c\
		srcs/exec/destroy_mlx.c\
		srcs/exec/doors.c\
		srcs/exec/doors2.c\
		srcs/exec/draw.c\
		srcs/exec/exec.c\
		srcs/exec/free.c\
		srcs/exec/keyboard.c\
		srcs/exec/malloc_struct.c\
		srcs/exec/minimap.c\
		srcs/exec/mouse.c\
		srcs/exec/mouvement.c\
    	srcs/exec/setup.c\
		\
		srcs/animation/animation_utils.c\
		srcs/animation/animation.c\
		srcs/animation/collectible.c\
		srcs/animation/hud.c\
		srcs/animation/init_img.c\
		srcs/animation/setup_animation.c\
		\

OBJS		= $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)


INCLUDES	= -I ./includes -I ./minilibx-linux


#================================#
#______           _           	||
#| ___ \         | |          	||
#| |_/ /___  __ _| | ___  ___ 	||
#|    // _ \/ _` | |/ _ \/ __|	||
#| |\ \  __/ (_| | |  __/\__ \	||
#\_| \_\___|\__, |_|\___||___/	||
#            __/ |            	||
#           |___/             	||
#================================#

TOTAL	= $(words $(SRCS) $(SRCS_BONUS))

all:
	@$(MAKE) -j12 $(NAME)

$(NAME): $(OBJS)
	@printf "\n"
	@$(MAKE) -C $(MLX_DIR) 2>/dev/null
	@if $(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -lm -o $(NAME); then \
		$(MAKE) name_ascii; \
		$(MAKE) user42; \
		printf "$(GREEN)$(GRAS)👌 Compilation terminée !$(RESET)\n\n"; \
	else \
		printf "\n$(RED)$(GRAS)Erreur de compilation !$(RESET)\n\n"; \
		exit 1; \
	fi

clean:
	@$(RM) -r $(OBJS_DIR)
	@$(RM) vgcore.*
	@printf "$(RED)Dossier .objects supprimé$(RESET)\n"

fclean: clean
	@$(RM) $(NAME) .last_colors extract.awk
	@printf "$(RED)$(NAME) supprimé$(RESET)\n"

re: fclean all

bonus:
	@$(MAKE) -j12 $(NAME) $(OBJS_BONUS)

bash:
	@bash --posix

#============================================================#
# _____                       _ _       _   _             	||
#/  __ \                     (_) |     | | (_)            	||
#| /  \/ ___  _ __ ___  _ __  _| | __ _| |_ _  ___  _ __  	||
#| |    / _ \| '_ ` _ \| '_ \| | |/ _` | __| |/ _ \| '_ \ 	||
#| \__/\ (_) | | | | | | |_) | | | (_| | |_| | (_) | | | |	||
# \____/\___/|_| |_| |_| .__/|_|_|\__,_|\__|_|\___/|_| |_|	||
#                      | |                                	||
#                      |_|                                	||
#============================================================#

INDEX = 0

define compile_msg
	$(eval INDEX=$(shell echo $$(($(INDEX)+1))))
	@printf "\r$(BLUE)$(GRAS)[$(INDEX)/$(TOTAL)]$(RESET) $(GRAS)Compilation: %-30s$(RESET)" "$(notdir $<)"
endef

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))
	@printf "\r$(BLUE)$(GRAS)[$(INDEX)/$(TOTAL)]$(RESET) $(GRAS)Compilation: %-30s$(RESET)" "$(notdir $<)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#============================#
# _____       _   _ _     	||
#|  _  |     | | (_) |    	||
#| | | |_   _| |_ _| |___ 	||
#| | | | | | | __| | / __|	||
#\ \_/ / |_| | |_| | \__ \	||
# \___/ \__,_|\__|_|_|___/	||
#============================#

# Statistiques du projet
stats:
	@printf "$(CYAN)Statistiques du projet:$(RESET)\n"
	@printf "	Fichiers .c	: %d\n" $(TOTAL)
	@printf "	Lignes code	: %d\n" $$(cat $(SRCS) $(SRCS_BONUS) | wc -l)
	@printf "	Headers		: %d\n" $$(find includes -name "*.h" | wc -l)

# Description des fonctions du projet
des:
	@printf "$(CYAN)$(GRAS)Description des fonctions du projet :$(RESET)\n\n\n\n"
	@find srcs -name "*.c" -exec awk '/^\/\/\// { c=1; print; next } c\
	 && /\(/ { print; print ""; print ""; c=0 }' {} +

val:
	@make re
	@$(VALGRIND) ./cub3d

cub:
	@make re
	@./cub3d

fun:
	@make re
	@funcheck ./cub3d -c "(ls | ls) && (qfdqw || ls)"

#===========================================# proubleme "ASSII"
#  ___       _      ___          _ _ 	   ||
# / _ \     | |    / _ \        (_|_)	   ||
#/ /_\ \_ __| |_  / /_\ \___ ___ _ _ 	   ||
#|  _  | '__| __| |  _  / __/ __| | |	   ||
#| | | | |  | |_  | | | \__ \__ \ | |	   ||
#\_| |_/_|   \__| \_| |_/___/___/_|_|	   ||
#===========================================#

COLOR_FILE	= .last_colors
COLOR_MAX	:= $(call get_random_color)$(GRAS)
COLOR_MAT	:= $(call get_random_color)$(GRAS)


# Fonction pour obtenir une couleur différente de la précédente
define get_random_color
$(shell \
	LAST=$$(cat $(COLOR_FILE) 2>/dev/null | head -1 || echo 0); \
	NEW=$$(od -An -N1 -tu1 /dev/urandom | tr -d ' '); \
	NEW=$$((NEW % 6 + 1)); \
	COUNT=0; \
	while [ "$$NEW" = "$$LAST" ] && [ $$COUNT -lt 10 ]; do \
		NEW=$$(od -An -N1 -tu1 /dev/urandom | tr -d ' '); \
		NEW=$$((NEW % 6 + 1)); \
		COUNT=$$((COUNT + 1)); \
	done; \
	echo $$NEW > $(COLOR_FILE); \
	printf "\033[0;3%dm" $$NEW \
)
endef

name_ascii:
	@printf "\n"
	@printf "$(call get_random_color)$(GRAS)"
	@printf ":'######::'##::::'##:'########:::'#######::'########::\n"
	@printf "'##... ##: ##:::: ##: ##.... ##:'##.... ##: ##.... ##:\n"
	@printf " ##:::..:: ##:::: ##: ##:::: ##:..::::: ##: ##:::: ##:\n"
	@printf " ##::::::: ##:::: ##: ########:::'#######:: ##:::: ##:\n"
	@printf " ##::::::: ##:::: ##: ##.... ##::...... ##: ##:::: ##:\n"
	@printf " ##::: ##: ##:::: ##: ##:::: ##:'##:::: ##: ##:::: ##:\n"
	@printf ". ######::. #######:: ########::. #######:: ########::\n"
	@printf ":......::::.......:::........::::.......:::........:::\n"
	@printf "$(RESET)\n"


user42:
	@printf "$(call get_random_color)$(GRAS)"
	@printf "                                                                                                                                                                         \n"
	@printf "$(COLOR_MAX)'##::::'##:'##::::'##:'##::::'##::'######:::'#######::'##::::'##:'########:'########:::::::::::'##::::'##::::'##:'########::'########:::::'###::::'##:::'##: \n"
	@printf "$(COLOR_MAX) ###::'###: ###::'###: ##:::: ##:'##... ##:'##.... ##: ##:::: ##: ##.....:: ##.... ##:::::::::'##::::: ##:::: ##: ##.... ##: ##.... ##:::'## ##:::. ##:'##:: \n"
	@printf "$(COLOR_MAX) ####'####: ####'####: ##:::: ##: ##:::..:: ##:::: ##: ##:::: ##: ##::::::: ##:::: ##::::::::'##:::::: ##:::: ##: ##:::: ##: ##:::: ##::'##:. ##:::. ####::: \n"
	@printf "$(COLOR_MAX) ## ### ##: ## ### ##: ##:::: ##:. ######:: ##:::: ##: ##:::: ##: ######::: ########::::::::'##::::::: #########: ########:: ########::'##:::. ##:::. ##:::: \n"
	@printf "$(COLOR_MAX) ##. #: ##: ##. #: ##: ##:::: ##::..... ##: ##:'## ##: ##:::: ##: ##...:::: ##.. ##::::::::'##:::::::: ##.... ##: ##.... ##: ##.. ##::: #########:::: ##:::: \n"
	@printf "$(COLOR_MAX) ##:.:: ##: ##:.:: ##: ##:::: ##:'##::: ##: ##:.. ##:: ##:::: ##: ##::::::: ##::. ##::::::'##::::::::: ##:::: ##: ##:::: ##: ##::. ##:: ##.... ##:::: ##:::: \n"
	@printf "$(COLOR_MAX) ##:::: ##: ##:::: ##:. #######::. ######::: ##### ##:. #######:: ########: ##:::. ##::::'##:::::::::: ##:::: ##: ########:: ##:::. ##: ##:::: ##:::: ##:::: \n"
	@printf "$(COLOR_MAX)..:::::..::..:::::..:::.......::::......::::.....:..:::.......:::........::..:::::..:::::..:::::::::::..:::::..::........:::..:::::..::..:::::..:::::..::::: \n"
	@printf "                                                              $(COLOR_MAX)$(RESET)                                                                                       \n"
	@printf "$(RESET)\n"

error_ascii:
	@printf "\n"
	@printf "$(RED)$(GRAS)"
	@printf "  _____ ____  ____   ___  ____                                \n"
	@printf " | ____|  _ \|  _ \ / _ \|  _ \                               \n"
	@printf " |  _| | |_) | |_) | | | | |_) |                              \n"
	@printf " | |___|  _ <|  _ <| |_| |  _ <                               \n"
	@printf " |_____|_|_\_\_| \_\\____/|_| \_\      _  _____ ___ ___  _   _ \n"
	@printf "  / ___/ _ \|  \/  |  _ \_ _| |      / \|_   _|_ _/ _ \| \ | |\n"
	@printf " | |  | | | | |\/| | |_) | || |     / _ \ | |  | | | | |  \| |\n"
	@printf " | |__| |_| | |  | |  __/| || |___ / ___ \| |  | | |_| | |\  |\n"
	@printf "  \____\___/|_|  |_|_|  |___|_____/_/   \_\_| |___\___/|_| \_|\n"
	@printf "$(RESET)\n"


#====================================#
#  ____  _   _  ___  _   ___   __	||
# |  _ \| | | |/ _ \| \ | \ \ / /	||
# | |_) | |_| | | | |  \| |\ V / 	||
# |  __/|  _  | |_| | |\  | | |  	||
# |_|   |_| |_|\___/|_| \_| |_|  	||
#====================================#

.PHONY: all bonus clean fclean re norm lines name_ascii user42

#makefile inspired by mvignes#