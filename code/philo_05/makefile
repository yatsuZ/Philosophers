# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 23:03:08 by yzaoui            #+#    #+#              #
#    Updated: 2023/11/04 23:13:58 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############### OBJ de PHILO

PHILO_THREAD_PATH =	./philo_src/thread/

PHILO_THREAD_FILES =	eat_sleep_think.c	\
						routine_and_fork.c

PHILO_STRUCT_PATH =	./philo_src/struct/

PHILO_STRUCT_FILES =	init_free_data.c		\
						init_free_all_mutex.c	\
						init_free_philo.c		\
						init_free_thread.c		\
						init_parsing.c

PHILO_PATH =	./philo_src/

PHILO_FILES =	main.c					\
				ft_calloc_and_time.c	\
				message_and_end.c		\
				gestion_thread.c

PHILO_SRC =	${addprefix ${PHILO_PATH}, ${PHILO_FILES}}	\
			${addprefix ${PHILO_STRUCT_PATH}, ${PHILO_STRUCT_FILES}}	\
			${addprefix ${PHILO_THREAD_PATH}, ${PHILO_THREAD_FILES}}

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
