#include "maze.h"
#include <stdlib.h>

void free_instance(instance_t *instance) {
    if (instance->renderer) {
        SDL_DestroyRenderer(instance->renderer);
    }
    if (instance->window) {
        SDL_DestroyWindow(instance->window);
    }
    SDL_Quit();
    free(instance);
}

void free_map(char **map, int height) {
    for (int i = 0; i < height; i++) {
        free(map[i]);
    }
    free(map);
}

