# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 11:29:26 by tzammar           #+#    #+#              #
#    Updated: 2026/02/04 19:25:08 by tzammar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      := cc
CFLAGS  := -Wall -Wextra -Werror
AR      := ar rcs
RM      := rm -f

LIBFT_DIR = ./libft
GNL_DIR = ./gnl
PRINTF_DIR = ./ft_printf
MINILIBX_DIR = ./minilibx-linux

INCLUDES = -I$(LIBFT_DIR) -I$(MINILIBX_DIR) -I$(GNL_DIR) -I$(PRINTF_DIR)
LFLAGS = -L$(LIBFT_DIR) -L$(MINILIBX_DIR) -L$(GNL_DIR) -L$(PRINTF_DIR)
LIBS = -l:libft.a -l:get_next_line.a -l:libftprintf.a -lmlx -lXext -lX11

SRCS	:= src/flood_fill.c src/render.c src/so_long.c src/utils_1.c src/utils_2.c src/validate_map.c\
 src/draw.c
OBJS    := $(SRCS:.c=.o)
NAME    := so_long

BONUS_SRCS	:= src_bonus/render_bonus.c src_bonus/so_long_bonus.c src_bonus/utils_1_bonus.c\
 src_bonus/utils_2_bonus.c src_bonus/utils_3_bonus.c src_bonus/utils_4_bonus.c src_bonus/validate_map_bonus.c
BONUS_OBJS    := $(BONUS_SRCS:.c=.o)
BONUS_NAME    := so_long_bonus

all: libft gnl printf minilibx $(NAME)

bonus: libft gnl printf minilibx $(BONUS_NAME)

libft:
	@echo "--- Entering libft directory to build..."
	$(MAKE) -C $(LIBFT_DIR)
	@echo "--- libft build complete."

gnl:
	@echo "--- Entering gnl directory to build..."
	$(MAKE) -C $(GNL_DIR)
	@echo "--- gnl build complete."

printf:
	@echo "--- Entering printf directory to build..."
	$(MAKE) -C $(PRINTF_DIR)
	@echo "--- printf build complete."

minilibx:
	@echo "--- Entering minilibx-linux directory to build..."
	$(MAKE) -C $(MINILIBX_DIR)
	@echo "--- minilibx build complete."

$(NAME): $(OBJS)
	@echo "--- Linking executable $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) $(INCLUDES) $(LIBS) -o $(NAME)
	@echo "--- Executable $(NAME) successfully created."

$(BONUS_NAME): $(BONUS_OBJS)
	@echo "--- Linking executable $(BONUS_NAME)..."
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LFLAGS) $(INCLUDES) $(LIBS) -o $(BONUS_NAME)
	@echo "--- Executable $(BONUS_NAME) successfully created."

%.o: %.c
	@echo "--- Compiling $<..."
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "--- Removing object files..."
	$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "--- Removing object files from sub-projects..."
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MINILIBX_DIR)
	$(MAKE) clean -C $(GNL_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	@echo "--- Removing executable $(NAME)..."
	$(RM) $(NAME) $(BONUS_NAME)
	@echo "--- Calling fclean in sub-projects..."
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(GNL_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus libft gnl printf minilibx
