#include "maze.h"

void handle_events(keys *key_state) {
HEAD
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIkey_state->esc = true;
						            }
				        if (event.type == SDL_KEYDOWN) {
						            switch (event.key.keysym.sym) {
								                    case SDLK_ESCAPE:
											                        key_state->esc = true;
														                    break;
																                    case SDLK_UP:
																                        key_state->up = true;
																			                    break;
																					                    case SDLK_DOWN:
																					                        key_state->down = true;
																								                    break;
																										                    case SDLK_LEFT:
																										                        key_state->left = true;
																													                    break;
																															                    case SDLK_RIGHT:
																															                        key_state->right = true;
																																		                    break;
																																				                }
							            }
					        if (event.type == SDL_KEYUP) {
							            switch (event.key.keysym.sym) {
									                    case SDLK_UP:
												                        key_state->up = false;
															                    break;
																	                    case SDLK_DOWN:
																	                        key_state->down = false;
																				                    break;
																						                    case SDLK_LEFT:
																						                        key_state->left = false;
																									                    break;
																											                    case SDLK_RIGHT:
																											                        key_state->right = false;
																														                    break;
																																                }
								            }
						    }
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

