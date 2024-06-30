#include "../maze.h"

/**
 * free_map - Free the memory allocated for the map
 * @map: The map to free
 * @map_h: Height of the map
 **/
void free_map(char **map, size_t map_h) {
    if (map == NULL) {
        return;
    }

    for (size_t i = 0; i < map_h; i++) {
        free(map[i]);
    }
    free(map);
}

/**
 * close_SDL - Close SDL and free resources
 * @instance: SDL instance to close
 **/
void close_SDL(SDL_Instance instance) {
    if (instance.renderer) {
        SDL_DestroyRenderer(instance.renderer);
    }
    if (instance.window) {
        SDL_DestroyWindow(instance.window);
    }
    SDL_Quit();
}

/**
 * free_memory - Free all allocated memory and close SDL
 * @map: The map to free
 * @map_h: Height of the map
 * @instance: SDL instance to close
 **/
void free_memory(char **map, size_t map_h, SDL_Instance instance) {
    free_map(map, map_h);
    close_SDL(instance);
}
