# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 10:35:35 by yatsu             #+#    #+#              #
#    Updated: 2023/10/29 19:18:19 by yatsu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############### OBJ de PHILO

PHILO_STRUCT_PATH =	./philo_src/struct/

PHILO_STRUCT_FILES =	init_data.c		\
						init_mutex.c	\
						init_philo.c	\
						init_thread.c	\
						parsing.c

PHILO_PATH =	./philo_src/

PHILO_FILES =	main.c		\
				ft_calloc.c	\
				end.c

PHILO_SRC =	${addprefix ${PHILO_PATH}, ${PHILO_FILES}}	\
			${addprefix ${PHILO_STRUCT_PATH}, ${PHILO_STRUCT_FILES}}

OBJ_PHILO = ${PHILO_SRC:.c=.o}

############### ligne de commande

RM = rm -rf

CC = cc
C_FLAGS = -g3 -Wall -Wextra -Werror

PROGRAM_NAME = philo

############### COMMANDE OBLIGATOIRE

${PROGRAM_NAME}: ${OBJ_PHILO}
	${CC} ${C_FLAGS} ${OBJ_PHILO} -o ${PROGRAM_NAME}

all : ${PROGRAM_NAME}

.c.o:
	${CC} ${C_FLAGS} -c $< -o ${<:.c=.o}

clean :
	${RM} ${OBJ_PHILO}

fclean : clean
	${RM} ${PROGRAM_NAME}

re : fclean all
