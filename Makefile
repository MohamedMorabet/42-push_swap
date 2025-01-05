CC = cc

# CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

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
		push_swap.c \
		stack_utils.c \

OBJS = ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
		${CC} -o ${NAME} ${OBJS} libft.a

%.o : %.c push_swap.h
		${CC} -o $@ -c $<

clean :
		rm -rf ${OBJS}

fclean : clean
		rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re