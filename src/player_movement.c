#include "maze.h"

void movement(keys key_state, double_s *plane, double_s *dir, double_s *play, char **map) {
    // Ensure plane, dir, play are properly initialized and not NULL
    if (!plane || !dir || !play || !map) return;

    // Movement logic here
    if (key_state.w) {
        play->x += dir->x * MOVE_SPEED;
        play->y += dir->y * MOVE_SPEED;
    }
    if (key_state.s) {
        play->x -= dir->x * MOVE_SPEED;
        play->y -= dir->y * MOVE_SPEED;
    }
    // Additional movement logic for left and right if needed
}
