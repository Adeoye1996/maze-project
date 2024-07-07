#include "maze.h"

/**
 * get_line_count - Get the number of lines in the file string
 * @file_string: String representation of the file content
 * 
 * Return: Number of lines in the file string
 */
size_t get_line_count(const char *file_string) {
    size_t count = 0;
    const char *temp = file_string;
    while ((temp = strchr(temp, '\n')) != NULL) {
        count++;
        temp++;
    }
    return count;
}

/**
 * plot_grid_points - Plot grid points and determine special positions
 * @maze: 2D array representing the maze
 * @play: Player's starting position
 * @win: Win position in the map
 * @cur_char: Current character in the line
 * @maze_line: Current line of the maze
 * @line: Current line number
 * @found_win: Pointer to flag indicating if win position is found
 */
void plot_grid_points(char **maze, double_s *play, int_s *win, size_t cur_char, const char *maze_line, size_t line, int *found_win) {
    maze[line][cur_char] = maze_line[cur_char];
    if (maze_line[cur_char] == 'p') {
        play->x = (double)cur_char + 0.5;
        play->y = (double)line + 0.5;
    } else if (maze_line[cur_char] == 'w') {
        win->x = (int)cur_char;
        win->y = (int)line;
        *found_win = 1;
    }
}

/**
 * create_map - Create a map from a file string
 * @filename: Name of the file containing the map data
 * @play: Pointer to player starting position
 * @win: Pointer to win position
 * @map_height: Pointer to store the height of the map
 * 
 * Return: Pointer to dynamically allocated 2D array representing the map
 */
char **create_map(const char *filename, double_s *play, int_s *win, size_t *map_height) {
    FILE *file;
    char *file_string;
    size_t file_length;
    char **maze;
    size_t line_count, line;
    int found_win = 0;

    // Read file contents into a string
    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    file_length = ftell(file);
    fseek(file, 0, SEEK_SET);

    file_string = malloc(file_length + 1);
    fread(file_string, 1, file_length, file);
    fclose(file);

    file_string[file_length] = '\0';

    // Count lines in the file to determine map height
    line_count = get_line_count(file_string);
    *map_height = line_count;

    // Allocate memory for the maze
    maze = malloc(line_count * sizeof(char *));
    for (line = 0; line < line_count; line++) {
        maze[line] = malloc(MAP_WIDTH + 1);
    }

    // Parse file string into the maze array
    line = 0;
    char *maze_line = strtok(file_string, "\n");
    while (maze_line) {
        size_t cur_char;
        for (cur_char = 0; cur_char < MAP_WIDTH; cur_char++) {
            plot_grid_points(maze, play, win, cur_char, maze_line, line, &found_win);
        }
        line++;
        maze_line = strtok(NULL, "\n");
    }

    free(file_string);

    if (!found_win) {
        fprintf(stderr, "Error: No win point found in the map\n");
        for (line = 0; line < line_count; line++) {
            free(maze[line]);
        }
        free(maze);
        return NULL;
    }

    return maze;
}
