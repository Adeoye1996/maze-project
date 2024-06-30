#ifndef MAZE_H
#define MAZE_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

typedef struct {
    double x;
    double y;
} double_s;

typedef struct {
    int x;
    int y;
} int_s;

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
} SDL_Instance;

typedef struct {
    int w;
    int s;
    int a;
    int d;
    int esc;
} keys;

typedef struct {
    char **map;
    double_s dir;
    double_s play;
    double_s plane;
    int_s win;
    size_t height;
} level;

// Function prototypes
int init_instance(SDL_Instance *instance);
void check_key_release_events(SDL_Event event, keys *key_press);
int check_key_press_events(SDL_Event event, keys *key_press);
int keyboard_events(keys *key_press);
char **create_map(const char *filename, double_s *play, int_s *win, size_t *map_height);
void free_map(char **map, size_t map_h);
void close_SDL(SDL_Instance instance);
void plot_grid_points(char **maze, double_s *play, int_s *win, size_t cur_char, const char *maze_line, size_t line, int *found_win);
void draw_background(SDL_Instance instance);
void draw_walls(char **map, double_s play, SDL_Instance instance, double_s dir, double_s plane);
void choose_color(SDL_Instance instance, char **map, int_s coord, int hit_side);
double get_wall_dist(char **map, double_s *dist_side, int_s *coord, int_s *step, double_s dist_del, double_s ray_dir);
void check_ray_dir(int_s *step, double_s *dist_side, double_s ray_pos, int_s coord, double_s dist_del, double_s ray_dir);
void movement(keys key_press, double_s *plane, double_s *dir, double_s *play, char **map);
int check_win(double_s play, int_s win, int *game_state);
void print_win();
void draw(SDL_Instance instance, char **map, double_s dir, double_s plane, double_s play);

#endif
