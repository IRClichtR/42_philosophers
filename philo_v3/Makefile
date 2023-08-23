NAME		= philo

SRCS		= $(addprefix SRCS/, \
check_chop.c    del_malloc.c            ft_isdigit.c    get_time.c          str_error.c \
check_death.c   display_status.c        ft_strdup.c     go_sleep.c          write_death.c \
check_finish.c  do_1th.c                ft_strlen.c     init_data.c         write_finish.c \
check_num.c     do_multiple_thinkers.c  ft_strncmp.c    main.c \
check_time.c    eat.c                   ft_substr.c     mod_chop_status.c \
chop_trylock.c  ft_atoi.c               get_ataraxia.c  search_for_truth.c)

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
