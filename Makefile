NAME = cub3D
LIB = libft/libft.a
FLAG = -Wall -Wextra -Werror -g
SRC = src/arg_error.c src/calculate.c src/cub3d.c src/file_io.c src/get_next_line_utils.c src/get_next_line.c src/img.c src/init.c src/main.c src/mapch.c src/mapch2.c src/mapch3.c src/mapcreate.c src/mapcreate2.c src/mod_cal.c src/mod_cal2.c src/mypixel.c src/push_key.c src/push_key2.c src/util.c src/util2.c src/lastfile.c\
		src/test_bb/bb_test.c src/test_bb/bb_name_test.c src/test_bb/bb_CF_test.c src/test_bb/bb_list_test.c src/test_bb/get_map_v_len.c src/test_bb/bb_get_map.c src/test_bb/bb_create_map.c src/test_bb/bb_check_map.c src/test_bb/bb_check_map_utils.c 
OBJ = $(SRC:%.c=%.o)
INCLUDE = includes
CC = gcc
XFLAG = -lXext -lX11 -lm
# XFLAG = -Imlx -lmlx -framework OpenGL -framework AppKit -lm

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(FLAG) -I $(INCLUDE) -o $(NAME) $(OBJ) libmlx_Linux.a $(LIB) $(XFLAG)

$(LIB):
	make -C libft

src/%.o: src/%.c
	$(CC) $(FLAG) -I $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

bonus: $(NAME)

.PHONY: all clean fclean re bonus
