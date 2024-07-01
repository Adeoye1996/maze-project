#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <SDL2/SDL.h>

typedef struct {
    int x;
    int y;
} int_s;

typedef struct {
    double x;
    double y;
} double_s;

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Surface *surface;
    SDL_Rect rect;
    int width;
    int height;
} instance_t;

typedef struct {
    char **map;
    double_s play;
    int_s win;
    int height;
    double_s dir;
    double_s plane;
} level;

typedef struct {
    bool w;
    bool a;
    bool s;
    bool d;
    bool esc;
} keys;

typedef struct {
    bool win;
} game_state_t;

instance_t *initialize_instance(void);
char **create_map(const char *file_name, double_s *play, int_s *win, int *height);
void handle_events(keys *key_state);
void movement(keys key_state, double_s *plane, double_s *dir, double_s *play, char **map);
bool check_win(double_s play, int_s win, game_state_t *game_state);
void print_win(void);
void draw(instance_t *instance, char **map, double_s dir, double_s plane, double_s play);
void free_instance(instance_t *instance);
void free_map(char **map, int height);

extern const char **levels[];
extern const int level_heights[];
extern int num_of_levels;

#endif /* MAZE_H */
