CC = cc

# CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

Bonus_name = checker

AR = ar

SRCS =	algorithms.c \
		main.c \
		manage_stack.c \
		operations__reverse_rotate.c \
		operations__rotate.c \
		operations__swap_push.c \
		operations_utils.c \
		parcing.c \
		push_swap__utils.c \
		push_swap__utils2.c \
		push_swap__utils3.c \
		push_swap.c \
		stack_utils.c \
		rank_stack.c \
		move_by_chunk.c \
		ft_split.c \
		ft_split__utils.c \

Bonus_SRCS = tester/operations__reverse_rotate__bonus.c \
			tester/operations__rotate__bonus.c \
			tester/operations__swap_push__bonus.c \
			tester/operations_utils__bonus.c \
			tester/main.c \
			tester/gnl/get_next_line.c \
			tester/gnl/get_next_line_utils.c \
			tester/ft_split__bonus.c \
			tester/ft_split__utils__bonus.c \
			tester/manage_stack__bonus.c \
			tester/stack_utils__bonus.c \

OBJS = ${SRCS:.c=.o}

Bonus_OBJS = ${Bonus_SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
		${CC} -o ${NAME} ${OBJS}

bonus : ${Bonus_OBJS}
		${CC} -o ${Bonus_name} ${Bonus_OBJS}

%.o : %.c push_swap.h
		${CC} -o $@ -c $<

clean :
		rm -rf ${OBJS} ${Bonus_OBJS}

fclean : clean
		rm -rf ${NAME} ${Bonus_name}

re : fclean all

.PHONY : all clean fclean re