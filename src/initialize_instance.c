#include "maze.h"

// Function to initialize the SDL instance
instance_t *initialize_instance(void) {
    fprintf(stderr, "Calling SDL_Init...\n");
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return NULL;
    }

    instance_t *instance = malloc(sizeof(instance_t));
    if (!instance) {
        fprintf(stderr, "Failed to allocate memory for instance\n");
        SDL_Quit();
        return NULL;
    }

    fprintf(stderr, "Creating SDL window...\n");
    instance->window = SDL_CreateWindow("Maze Game",
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        640, 480,
                                        SDL_WINDOW_SHOWN);
    if (!instance->window) {
        fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        free(instance);
        SDL_Quit();
        return NULL;
    }

    fprintf(stderr, "Creating SDL renderer...\n");
    instance->renderer = SDL_CreateRenderer(instance->window, -1, SDL_RENDERER_ACCELERATED);
    if (!instance->renderer) {
        fprintf(stderr, "Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(instance->window);
        free(instance);
        SDL_Quit();
        return NULL;
    }

    fprintf(stderr, "SDL instance initialized successfully.\n");
    return instance;
}
