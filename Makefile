NAME = PROG

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread

SRC = threads_mutexes.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	rm $(OBJS) $(NAME)

