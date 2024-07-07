#ifndef MAZE_H
#define MAZE_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#define MAP_HEIGHT 24
#define MAP_WIDTH 24
#define MOVE_SPEED 0.1

#define SCREEN_WIDTH 640  // Define screen width
#define SCREEN_HEIGHT 480 // Define screen height

// Define the keys struct with required members
typedef struct {
    bool esc;
    bool w;
    bool a;
    bool s;
    bool d;
} keys;

typedef struct {
    double x;
    double y;
} double_s;

typedef struct {
    int x;
    int y;
} int_s;

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;  // Add window member to instance_t
} instance_t;

typedef struct {
    char **map;
    size_t height;
    double_s play;  // Change play to double_s
    int_s win;
    double_s dir;
    double_s plane;
} level;

typedef struct {
    bool win;
} game_state_t;

char **create_map(const char *filename, double_s *play, int_s *win, size_t *height);
void free_map(char **map, size_t height);
int check_win(double_s play, int_s win, game_state_t *game_state);  // Ensure this matches
void print_win(void);
instance_t *initialize_instance(void);  // Add declaration for initialize_instance
void handle_events(keys *key_state);    // Add declaration for handle_events
void movement(keys key_state, double_s *plane, double_s *dir, double_s *play, char **map); // Add declaration for movement
void draw(instance_t *instance, char **map, double_s dir, double_s plane, double_s play);  // Add declaration for draw
void free_instance(instance_t *instance);  // Ensure free_instance is declared

#endif // MAZE_H
