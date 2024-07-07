# Compiler to use
CC = gcc

# Flags to create object files with
CFLAGS = -g -Wall -Werror -Wextra -pedantic -I./src -I./inc

# Flags to link the SDL2 library
SDL_FLAGS = -I/usr/local/include/SDL2 -L/usr/lib/x86_64-linux-gnu -lSDL2 -lm

# All C program files
SRC = ./src/create_map.c ./src/build_world.c ./src/handle_events.c ./src/memory_management.c \
      ./src/render.c ./src/initialize_instance.c ./src/player_movement.c ./src/game_win.c \
      ./src/main.c

# The names of all object files
OBJ = $(SRC:.c=.o)

# Executable name
NAME = maze

# Removal command
RM = rm

# Compile all files into the executable
# CFLAGS will only be used when creating object files
# SDL_FLAGS includes necessary libraries to link
all: $(OBJ) levels.o
	$(CC) $(OBJ) levels.o -o $(NAME) $(SDL_FLAGS)

# Remove all object files (.o)
clean:
	$(RM) -f $(OBJ)

# Remove temp files, object files, and executable
fclean: clean
	$(RM) -f $(NAME)

# Run full clean and recompile all files
re: fclean all

# Pattern rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
