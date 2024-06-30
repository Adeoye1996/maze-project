#ifndef RAYCASTING_H
#define RAYCASTING_H

#include <SDL2/SDL.h>

void perform_raycasting(SDL_Renderer *renderer, int map[8][8], double playerX, double playerY, double playerAngle, SDL_Texture *wallTexture);
void draw_map(SDL_Renderer *renderer, int map[8][8], double playerX, double playerY, double playerAngle);

#endif /* RAYCASTING_H */
