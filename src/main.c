#include "../maze.h"

/**
 * main - entry point of the game
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[]) {
    SDL_Instance instance;
    keys key_state = {0, 0, 0, 0, 0};
    level current_level;

    if (init_instance(&instance) != 0)
        return (1);

    if (argc == 2) {
        current_level.map = create_map(argv[1], &current_level.play, &current_level.win, &current_level.height);
    } else {
        current_level.map = create_map("default_map.txt", &current_level.play, &current_level.win, &current_level.height);
    }

    if (!current_level.map) {
        fprintf(stderr, "Error: could not load map\n");
        return (1);
    }

    int game_state = 0;
    while (keyboard_events(&key_state)) {
        movement(key_state, &current_level.plane, &current_level.dir, &current_level.play, current_level.map);
        if (check_win(current_level.play, current_level.win, &game_state)) {
            print_win();
            break;
        }
        draw(instance, current_level.map, current_level.dir, current_level.plane, current_level.play);
        SDL_RenderPresent(instance.renderer);
        SDL_Delay(16);
    }

    free_map(current_level.map, current_level.height);
    close_SDL(instance);
    return (0);
}
