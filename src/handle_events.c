#include "../maze.h"

/**
 * check_key_release_events - Check for key release events
 * @event: SDL event to process
 * @key_press: Pointer to keys struct managing key states
 **/
void check_key_release_events(SDL_Event event, keys *key_press) {
    if (event.type == SDL_KEYUP) {
        switch (event.key.keysym.sym) {
            case SDLK_w:
                key_press->up = 0;
                break;
            case SDLK_s:
                key_press->down = 0;
                break;
            case SDLK_a:
                key_press->left = 0;
                break;
            case SDLK_d:
                key_press->right = 0;
                break;
        }
    }
}

/**
 * check_key_press_events - Check for key press events
 * @event: SDL event to process
 * @key_press: Pointer to keys struct managing key states
 * 
 * Returns: 1 if quit event is encountered, 0 otherwise
 **/
int check_key_press_events(SDL_Event event, keys *key_press) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_w:
                key_press->up = 1;
                break;
            case SDLK_s:
                key_press->down = 1;
                break;
            case SDLK_a:
                key_press->left = 1;
                break;
            case SDLK_d:
                key_press->right = 1;
                break;
        }
    } else if (event.type == SDL_QUIT) {
        return (1);
    }
    return (0);
}

/**
 * keyboard_events - Process keyboard events
 * @key_press: Pointer to keys struct managing key states
 * 
 * Returns: 0 if no quit event is encountered, 1 otherwise
 **/
int keyboard_events(keys *key_press) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYUP) {
            check_key_release_events(event, key_press);
        } else if (event.type == SDL_KEYDOWN) {
            if (check_key_press_events(event, key_press)) {
                return 1;
            }
        } else if (event.type == SDL_QUIT) {
            return (1);
        }
    }
    return (0);
}
