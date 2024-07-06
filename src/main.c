#include "maze.h"
#include "levels.h"

int main(int argc, char *argv[]) {
	instance_t *instance = initialize_instance();
	if (!instance) {
		fprintf(stderr, "Failed to initialize instance\n");

		return (1);
    }
	level current_level = {0};  // Initialize all fields to zero/NULL
	current_level.plane = (double_s){0.0, 0.66}; // Default plane vector
	current_level.dir = (double_s){-1.0, 0.0};   // Default direction vector

    if (argc > 1) {
        current_level.map = create_map(argv[1], &current_level.play, &current_level.win, &current_level.height);
        if (!current_level.map) {
            fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
            fprintf(stderr, "Error: could not load map\n");
            // Use level1 as the default fallback map
            current_level.map = (char **)level1;
            current_level.height = level_heights[0];
            current_level.play = (double_s){1, 2}; // default player start for level1
            current_level.win = (int_s){13, 13};   // default win position for level1
        }
    } else {
        // Use level1 as the default map
        current_level.map = (char **)level1;
        current_level.height = level_heights[0];
        current_level.play = (double_s){1, 2}; // default player start for level1
        current_level.win = (int_s){13, 13};   // default win position for level1
    }

    keys key_state = {0};  // Initialize all fields to zero
    game_state_t game_state = {0};  // Initialize all fields to zero

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
    if (argc > 1 && current_level.map != (char **)level1) {
        free_map(current_level.map, current_level.height);
    }

    return (0);
}
