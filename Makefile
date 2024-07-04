NAME1 = server
NAME = client

SRC = client.c
SRC1 = server.c make_utils.c libft.c

OBJ = $(SRC:.c=.o)

OBJ1 = $(SRC1:.c=.o)

CC = cc

CFLAGS = -Werror -Wall -Wextra -g

all: $(NAME1) $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME1): $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
	rm -f $(OBJ)
	rm -f $(OBJ1)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME1)

re: fclean all
