#include "maze.h"

void handle_events(keys *key_state) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            key_state->esc = true;
        }
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    key_state->esc = true;
                    break;
                case SDLK_w:
                    key_state->w = true;
                    break;
                case SDLK_s:
                    key_state->s = true;
                    break;
                case SDLK_a:
                    key_state->a = true;
                    break;
                case SDLK_d:
                    key_state->d = true;
                    break;
            }
        }
        if (event.type == SDL_KEYUP) {
            switch (event.key.keysym.sym) {
                case SDLK_w:
                    key_state->w = false;
                    break;
                case SDLK_s:
                    key_state->s = false;
                    break;
                case SDLK_a:
                    key_state->a = false;
                    break;
                case SDLK_d:
                    key_state->d = false;
                    break;
            }
        }
    }
}
