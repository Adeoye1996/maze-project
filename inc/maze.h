#ifndef MAZE_H
#define MAZE_H

#include <SDL2/SDL.h>
#include <stdbool.h>

// Define struct for instance
typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
} instance_t;

// Define structs for game state
typedef struct {
    double x;
    double y;
} double_s;

typedef struct {
    int x;
    int y;
} int_s;

typedef struct {
    bool esc;
    bool up;
    bool down;
    bool left;
    bool right;
} keys;

typedef struct {
    char **map;
    int height;
    double_s play;
    int_s win;
} level;

typedef struct {
    bool win;
} game_state_t;

// Function declarations
instance_t *initialize_instance(void);
void free_instance(instance_t *instance);
char **create_map(const char *filename, double_s *play, int_s *win, int *height);
void handle_events(keys *key_state);
void movement(keys key_state, double_s *plane, double_s *dir, double_s *play, char **map);
void draw(instance_t *instance, char **map, double_s dir, double_s plane, double_s play);
bool check_win(double_s play, int_s win, game_state_t *game_state);
void print_win(void);
void free_map(char **map, int height);

#endif // MAZE_H
