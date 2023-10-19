SRCS = ft_print_resoure.c \
		ft_printf.c \
		ft_libft.c
OBJS = ${SRCS:%.c=%.o}
NAME = libftprintf.a
CC = cc
Cflags = -Wall -Wextra -Werror

AR = ar rc
RM = rm -f

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I./ -c $(SRCS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

