NAME = server
NAME2 = client

BONUS = server_bonus
BONUS2 = client_bonus

CC = clang
FLAGS = -Wall -Wextra -Werror
INCLUDES = ./includes/minitalk.h
INCLUDES_B = ./includes/minitalk_bonus.h

SRC_PATH = ./mandatory/
SRC_PATH_B = ./bonus/

SRC = $(SRC_PATH)server.c
SRC_CLIENT = $(SRC_PATH)client.c

OBJ = $(SRC:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

SRC_BONUS = $(SRC_PATH_B)server_bonus.c
SRC_CLIENT_BONUS = $(SRC_PATH_B)client_bonus.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

all: $(NAME) $(NAME2) $(INCLUDES)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)

$(NAME2): $(OBJ_CLIENT)
	@$(CC) $(FLAGS) -o $(NAME2) $(OBJ_CLIENT)

bonus: $(BONUS) $(BONUS2) $(INCLUDES_B)

$(BONUS): $(OBJ_BONUS)
	@$(CC) $(FLAGS) -o $(BONUS) $(OBJ_BONUS)

$(BONUS2): $(OBJ_CLIENT_BONUS)
	@$(CC) $(FLAGS) -o $(BONUS2) $(OBJ_CLIENT_BONUS)

git:
	@git add .
	@git commit -m "$m"
	@git push
#make git m="blablabla"

clean:
	@rm -f $(OBJ) $(OBJ_CLIENT) $(OBJ_BONUS) $(OBJ_CLIENT_BONUS)

fclean:
	@rm -f $(NAME) $(OBJ) $(NAME2) $(OBJ_CLIENT) $(BONUS) $(BONUS2) $(OBJ_BONUS) $(OBJ_CLIENT_BONUS)

re: fclean all

#rebonus: fclean bonus


.PHONY:		all clean fclean re bonus rebonus