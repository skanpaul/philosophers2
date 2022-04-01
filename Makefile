# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 11:43:07 by ski               #+#    #+#              #
#    Updated: 2022/03/22 11:43:10 by ski              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= philo

CC		= gcc
CFLAG	= -Wall -Wextra -Werror
TFLAG	= -pthread

RM		= rm -f
# **************************************************************************** #

# SRC		= $(wildcard *.c)
SRC		=	print_status_1.c \
			check_end.c \
			print_status_2.c \
			check_end_utils.c \
			start_thread.c \
			data.c \
			philo_activity.c \
			timestamp_utils.c \
			init_philo.c \
			philo_activity_utils_1.c \
			utils_1.c \
			main.c \
			philo_activity_utils_2.c \
			utils_2.c \
			print_error.c

OBJ		= $(SRC:.c=.o)

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(TFLAG) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# **************************************************************************** #

.PHONY: all clean fclean re
