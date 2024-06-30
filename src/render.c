#include "../maze.h"

void draw(SDL_Instance instance, char **map, double_s play, double_s dir, double_s plane) {
    // Draw background
    draw_background(instance);

    // Draw walls
    draw_walls(map, play, instance, dir, plane);

    // Present renderer
    SDL_RenderPresent(instance.renderer);
}

void draw_background(SDL_Instance instance) {
    // Set draw color for the ceiling
    SDL_SetRenderDrawColor(instance.renderer, 135, 206, 235, 255);  // Sky blue color

    // Draw the ceiling
    SDL_Rect ceiling = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
    SDL_RenderFillRect(instance.renderer, &ceiling);

    // Set draw color for the floor
    SDL_SetRenderDrawColor(instance.renderer, 169, 169, 169, 255);  // Dark gray color

    // Draw the floor
    SDL_Rect floor = {0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
    SDL_RenderFillRect(instance.renderer, &floor);
}

void draw_walls(char **map, double_s play, SDL_Instance instance, double_s dir, double_s plane) {
    int x;
    for (x = 0; x < SCREEN_WIDTH; x++) {
        // Calculate ray position and direction
        double camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
        double_s ray_pos = {play.x, play.y};
        double_s ray_dir = {dir.x + plane.x * camera_x, dir.y + plane.y * camera_x};

        // Which box of the map we're in
        int_s coord = {(int)ray_pos.x, (int)ray_pos.y};

        // Length of ray from current position to next x or y-side
        double_s dist_side;

        // Length of ray from one x or y-side to next x or y-side
        double_s dist_del = {fabs(1 / ray_dir.x), fabs(1 / ray_dir.y)};
        int_s step;

        // Calculate step and initial side distance
        check_ray_dir(&step, &dist_side, ray_pos, coord, dist_del, ray_dir);

        // Perform DDA
        int hit = 0;  // Was there a wall hit?
        int hit_side; // Was a NS or a EW wall hit?
        while (hit == 0) {
            // Jump to next map square, OR in x-direction, OR in y-direction
            if (dist_side.x < dist_side.y) {
                dist_side.x += dist_del.x;
                coord.x += step.x;
                hit_side = 0;
            } else {
                dist_side.y += dist_del.y;
                coord.y += step.y;
                hit_side = 1;
            }

            // Check if ray has hit a wall
            if (map[coord.x][coord.y] > '0') {
                hit = 1;
            }
        }

        // Calculate distance projected on camera direction
        double wall_dist = get_wall_dist(&dist_side, &coord, &step, ray_dir);

        // Calculate height of line to draw on screen
        int line_height = (int)(SCREEN_HEIGHT / wall_dist);

        // Calculate lowest and highest pixel to fill in current stripe
        int draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
        if (draw_start < 0) {
            draw_start = 0;
        }
        int draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
        if (draw_end >= SCREEN_HEIGHT) {
            draw_end = SCREEN_HEIGHT - 1;
        }

        // Choose wall color
        choose_color(instance, map, coord, hit_side);

        // Draw the vertical line
        SDL_RenderDrawLine(instance.renderer, x, draw_start, x, draw_end);
    }
}

void check_ray_dir(int_s *step, double_s *dist_side, double_s ray_pos, int_s coord, double_s dist_del, double_s ray_dir) {
    // Calculate step and initial side distance
    if (ray_dir.x < 0) {
        step->x = -1;
        dist_side->x = (ray_pos.x - coord.x) * dist_del.x;
    } else {
        step->x = 1;
        dist_side->x = (coord.x + 1.0 - ray_pos.x) * dist_del.x;
    }

    if (ray_dir.y < 0) {
        step->y = -1;
        dist_side->y = (ray_pos.y - coord.y) * dist_del.y;
    } else {
        step->y = 1;
        dist_side->y = (coord.y + 1.0 - ray_pos.y) * dist_del.y;
    }
}

double get_wall_dist(double_s *dist_side, int_s *coord, int_s *step, double_s ray_dir) {
    double wall_dist;
    if (dist_side->x < dist_side->y) {
        wall_dist = (coord->x - ray_dir.x + (1 - step->x) / 2) / ray_dir.x;
    } else {
        wall_dist = (coord->y - ray_dir.y + (1 - step->y) / 2) / ray_dir.y;
    }
    return wall_dist;
}

void choose_color(SDL_Instance instance, char **map, int_s coord, int hit_side) {
    // Choose color based on the wall hit
    switch (map[coord.x][coord.y]) {
        case '1':
            SDL_SetRenderDrawColor(instance.renderer, 255, 0, 0, 255); // Red
            break;
        case '2':
            SDL_SetRenderDrawColor(instance.renderer, 0, 255, 0, 255); // Green
            break;
        case '3':
            SDL_SetRenderDrawColor(instance.renderer, 0, 0, 255, 255); // Blue
            break;
        case '4':
            SDL_SetRenderDrawColor(instance.renderer, 255, 255, 0, 255); // Yellow
            break;
        default:
            SDL_SetRenderDrawColor(instance.renderer, 255, 255, 255, 255); // White
            break;
    }

    // Darken color for y-sides
    if (hit_side == 1) {
        Uint8 r, g, b, a;
        SDL_GetRenderDrawColor(instance.renderer, &r, &g, &b, &a);
        SDL_SetRenderDrawColor(instance.renderer, r / 2, g / 2, b / 2, 255);
    }
}
