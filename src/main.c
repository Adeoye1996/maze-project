#include "maze.h"
#include "levels.h"

int main(int argc, char *argv[]) {
    instance_t *instance = initialize_instance();

    level current_level;

    if (argc > 1) {
        current_level.map = create_map(argv[1], &current_level.play, &current_level.win, &current_level.height);
        if (!current_level.map) {
            printf("Error: Could not open file %s\n", argv[1]);
            printf("Error: could not load map\n");
            // Use level1 as the default fallback map
            current_level.map = (char **)levels[0];
            current_level.height = level_heights[0];
            current_level.play = (double_s){1, 2}; // default player start for level1
            current_level.win = (int_s){13, 13}; // default win position for level1
        }
    } else {
        // Use level1 as the default map
        current_level.map = (char **)levels[0];
        current_level.height = level_heights[0];
        current_level.play = (double_s){1, 2}; // default player start for level1
        current_level.win = (int_s){13, 13}; // default win position for level1
    }

    keys key_state = {0, 0, 0, 0};
    game_state_t game_state = {0};

    while (!key_state.esc && !game_state.win) {
        handle_events(&key_state);
        movement(key_state, &current_level.plane, &current_level.dir, &current_level.play, current_level.map);
        if (check_win(current_level.play, current_level.win, &game_state)) {
            print_win();
            break;
        }
        draw(instance, current_level.map, current_level.dir, current_level.plane, current_level.play);
    }

    free_instance(instance);
    if (argc > 1 && current_level.map != (char **)levels[0]) {
        free_map(current_level.map, current_level.height);
    }

    return (0);
}
