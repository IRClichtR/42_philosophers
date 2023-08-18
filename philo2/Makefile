NAME		= philo

SRCS		= $(addprefix SRCS/, \
check_av.c      del_malloc.c            eat.c         get_ataraxia.c  main.c              write_death.c \
check_death.c   display_status.c        ft_atoi.c     get_time.c      write_finish.c \
check_eating.c  do_1th.c                ft_strlen.c   go_sleep.c      search_for_truth.c \
check_finish.c  do_multiple_thinkers.c  ft_strncmp.c  init_data.c     str_error.c )

OBJS_DIR	= OBJS

OBJS		= $(addprefix $(OBJS_DIR)/, $(patsubst %.c, %.o, $(notdir $(SRCS))))

CC			= cc -O0

CFLAGS		= -g3 -Werror -Wextra -Wall -pthread -fsanitize=thread

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJS_DIR)/%.o:*/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

norme:
	norminette $(SRCS)

.PHONY: all clean fclean re
