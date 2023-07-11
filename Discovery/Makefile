NAME = philo

SRCS = main.c

OBJS = $(SRCS:.c=.o)

CC = cc -O0

CFLAGS = -Werror -Wextra -Wall -pthread

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJS): %.o:%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

re: fclean all

clean:
	rm -rf main.o

fclean: clean
	rm -rf $(NAME)

norme:
	norminette $(SRCS)

.PHONY: all clean fclean re
