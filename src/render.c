#include "maze.h"
#include <stdio.h>
#include <math.h>  // Ensure to include math header for fabs

// Function prototypes
void draw_background(instance_t *instance);
void draw_walls(char **map, double_s play, instance_t *instance, double_s dir, double_s plane);
void check_ray_dir(int_s *step, double_s *side_dist, double_s ray_pos, int_s coord, double_s dist_del, double_s ray_dir);
double get_wall_dist(double_s *side_dist, int_s *coord, int_s *step, double_s ray_dir);
void choose_color(instance_t *instance, char **map, int_s coord, int hit_side);

void draw(instance_t *instance, char **map, double_s dir, double_s plane, double_s play) {
    draw_background(instance);
    draw_walls(map, play, instance, dir, plane);
}

void draw_background(instance_t *instance) {
    (void)instance; // Mark parameter as used to avoid warnings
    // Implementation of draw_background
}

void draw_walls(char **map, double_s play, instance_t *instance, double_s dir, double_s plane) {
    // Example:
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        double cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
        double_s ray_dir = { dir.x + plane.x * cameraX, dir.y + plane.y * cameraX };

        int_s map_pos = { (int)play.x, (int)play.y };
        double_s side_dist;
        double_s delta_dist = { fabs(1 / ray_dir.x), fabs(1 / ray_dir.y) };
        double perp_wall_dist;

        int_s step;
        int hit = 0;
        int side;

        check_ray_dir(&step, &side_dist, play, map_pos, delta_dist, ray_dir);

        // Perform DDA
        while (hit == 0) {
            if (side_dist.x < side_dist.y) {
                side_dist.x += delta_dist.x;
                map_pos.x += step.x;
                side = 0;
            } else {
                side_dist.y += delta_dist.y;
                map_pos.y += step.y;
                side = 1;
            }

            if (map[map_pos.x][map_pos.y] > 0) hit = 1;
        }

        perp_wall_dist = get_wall_dist(&side_dist, &map_pos, &step, ray_dir);

        int line_height = (int)(SCREEN_HEIGHT / perp_wall_dist);
        int draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
        if (draw_start < 0) draw_start = 0;
        int draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
        if (draw_end >= SCREEN_HEIGHT) draw_end = SCREEN_HEIGHT - 1;

        choose_color(instance, map, map_pos, side);

        // Render the vertical stripe in the x-th position of the screen
        SDL_RenderDrawLine(instance->renderer, x, draw_start, x, draw_end);
    }
}

void check_ray_dir(int_s *step, double_s *side_dist, double_s ray_pos, int_s coord, double_s dist_del, double_s ray_dir) {
    (void)step;       // Mark parameter as used to avoid warnings
    (void)side_dist;  // Mark parameter as used to avoid warnings
    (void)ray_pos;    // Mark parameter as used to avoid warnings
    (void)coord;      // Mark parameter as used to avoid warnings
    (void)dist_del;   // Mark parameter as used to avoid warnings
    (void)ray_dir;    // Mark parameter as used to avoid warnings
    // Implementation of check_ray_dir
}

double get_wall_dist(double_s *side_dist, int_s *coord, int_s *step, double_s ray_dir) {
    (void)side_dist;  // Mark parameter as used to avoid warnings
    (void)coord;      // Mark parameter as used to avoid warnings
    (void)step;       // Mark parameter as used to avoid warnings
    (void)ray_dir;    // Mark parameter as used to avoid warnings
    // Implementation of get_wall_dist
    return 0.0; // Return a dummy value for now
}

void choose_color(instance_t *instance, char **map, int_s coord, int hit_side) {
    (void)instance;  // Mark parameter as used to avoid warnings
    (void)map;       // Mark parameter as used to avoid warnings
    (void)coord;     // Mark parameter as used to avoid warnings
    (void)hit_side;  // Mark parameter as used to avoid warnings
    // Implementation of choose_color
}
