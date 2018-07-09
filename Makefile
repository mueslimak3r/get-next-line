NAME = getnl

SRC = main.c get_next_line.c strchr_int.c strsubcpy.c

OBJ = $(SRC:.c=.o)

SRC_PATH = ./

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

LIBFT =	libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -I $(SRC_PATH) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
	@$(CC) $(FLAGS) -c $(SRC_POS)

$(LIBFT):
	@make -C $(LPATH)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

just: re clean

.PHONY : all, re, clean, fclean, just
