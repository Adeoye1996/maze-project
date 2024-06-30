#include "../maze.h"

/**
 * movement - handle player movement
 * @key_press: structure containing the current key states
 * @plane: direction plane of the player
 * @dir: direction vector of the player
 * @play: player position
 * @map: the game map
 */
void movement(keys key_press, double_s *plane, double_s *dir, double_s *play, char **map) {
    // Define movement speed
    double moveSpeed = 0.05;
    double rotSpeed = 0.03;

    // Move forward if no wall in front
    if (key_press.w) {
        if (map[(int)(play->x + dir->x * moveSpeed)][(int)(play->y)] == '0')
            play->x += dir->x * moveSpeed;
        if (map[(int)(play->x)][(int)(play->y + dir->y * moveSpeed)] == '0')
            play->y += dir->y * moveSpeed;
    }
    // Move backward if no wall behind
    if (key_press.s) {
        if (map[(int)(play->x - dir->x * moveSpeed)][(int)(play->y)] == '0')
            play->x -= dir->x * moveSpeed;
        if (map[(int)(play->x)][(int)(play->y - dir->y * moveSpeed)] == '0')
            play->y -= dir->y * moveSpeed;
    }
    // Rotate right
    if (key_press.d) {
        // Both camera direction and camera plane must be rotated
        double oldDirX = dir->x;
        dir->x = dir->x * cos(-rotSpeed) - dir->y * sin(-rotSpeed);
        dir->y = oldDirX * sin(-rotSpeed) + dir->y * cos(-rotSpeed);
        double oldPlaneX = plane->x;
        plane->x = plane->x * cos(-rotSpeed) - plane->y * sin(-rotSpeed);
        plane->y = oldPlaneX * sin(-rotSpeed) + plane->y * cos(-rotSpeed);
    }
    // Rotate left
    if (key_press.a) {
        // Both camera direction and camera plane must be rotated
        double oldDirX = dir->x;
        dir->x = dir->x * cos(rotSpeed) - dir->y * sin(rotSpeed);
        dir->y = oldDirX * sin(rotSpeed) + dir->y * cos(rotSpeed);
        double oldPlaneX = plane->x;
        plane->x = plane->x * cos(rotSpeed) - plane->y * sin(rotSpeed);
        plane->y = oldPlaneX * sin(rotSpeed) + plane->y * cos(rotSpeed);
    }
}
