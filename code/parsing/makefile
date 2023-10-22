# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 15:19:54 by yatsu             #+#    #+#              #
#    Updated: 2023/10/22 19:34:03 by yatsu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############### OBJ UTILE

SRC_UTILS_PATH =	./src/utils/

SRC_UTILS_FILES =	parsing.c

SRC_UTILS = ${addprefix ${SRC_UTILS_PATH}, ${SRC_UTILS_FILES}}

OBJ_UTILS = ${SRC_UTILS:.c=.o}

############### OBJ de PHILO

SRC_PHILO_PATH =	./src/philo/

SRC_PHILO_FILES =	main.c

SRC_PHILO = ${addprefix ${SRC_PHILO_PATH}, ${SRC_PHILO_FILES}}

OBJ_PHILO = ${SRC_PHILO:.c=.o} ${OBJ_UTILS}

############### COMPILATION

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
