#ifndef MAZE_H
#define MAZE_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "levels.h"

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
} instance_t;

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
void handle_events(keys *key_state);
void movement(keys key_state, double_s *plane, double_s *dir, double_s *play, char **map);
void draw(instance_t *instance, char **map, double_s dir, double_s plane, double_s play);
bool check_win(double_s play, int_s win, game_state_t *game_state);
void free_instance(instance_t *instance);
void print_win(void);

#endif /* MAZE_H */
