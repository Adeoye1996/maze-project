#ifndef LEVELS_H
#define LEVELS_H

#include "maze.h"  // Include maze.h to use the defined types

extern const char *level1[];
extern const char *level2[];
extern const char *level3[];
extern const char *level4[];
extern const char *level5[];
extern const char *level6[];
extern const char *level7[];
extern const char *level8[];

extern const char **levels[];
extern const int level_heights[];
extern int num_of_levels;

// Function declarations
char **create_map(const char *filename, double_s *play, int_s *win, size_t *height);
void free_map(char **map, size_t height);

#endif /* LEVELS_H */
