NAME = server
NAME2 = client

CC = clang
FLAGS = -Wall -Wextra -Werror
INCLUDES = ./includes/minitalk.h

SRC_PATH = ./mandatory/
SRC_BONUS = ./bonus/

SRC = $(SRC_PATH)server.c
SRC_CLIENT = $(SRC_PATH)client.c

OBJ = $(SRC:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all: $(NAME) $(NAME2) $(INCLUDES)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)

$(NAME2): $(OBJ_CLIENT)
	@$(CC) $(FLAGS) -o $(NAME2) $(OBJ_CLIENT)

git:
	@git add .
	@git commit -m "$m"
	@git push
#make git m="blablabla"

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(NAME) $(OBJ) $(NAME2) $(OBJ_CLIENT)

re: fclean all

#rebonus: fclean bonus


.PHONY:		all clean fclean re bonus rebonus