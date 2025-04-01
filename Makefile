NAME = PROG

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread

SRC = ret_value_from_threads.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	rm $(OBJS) $(NAME)

re : clean all

