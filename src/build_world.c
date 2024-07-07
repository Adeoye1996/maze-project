#include "maze.h"
#include <stdio.h>
#include <stdlib.h>

level *build_world_from_args(int num_of_lvls, char *level_files[]) {
    level *levels;
    size_t map_height;

    levels = malloc(sizeof(level) * num_of_lvls);
    if (!levels) {
        fprintf(stderr, "Error: Could not allocate memory for levels\n");
        return NULL;
    }

    for (int i = 0; i < num_of_lvls; i++) {
        // Initialize stage with appropriate values
        level stage = {NULL, 0, {0.0, 0.0}, {0.0, 0.0}, {-1.0, 0.0}, {0.0, 0.5}};
        stage.map = create_map(level_files[i], &stage.play, &stage.win, &map_height);
        if (stage.map == NULL) {
            fprintf(stderr, "Error: Could not create map for level %d\n", i);
            free(levels);
            return NULL;
        }
        stage.height = map_height;
        levels[i] = stage;
    }

    return levels;
}
