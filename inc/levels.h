#ifndef LEVELS_H
#define LEVELS_H

typedef struct {
    double x, y;
} double_s;

typedef struct {
    int x, y;
} int_s;

typedef struct {
    char **map;
    int height;
    double_s play;
    int_s win;
    double_s plane;  // Add this
    double_s dir;    // Add this
} level;

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

char **create_map(const char *filename, double_s *play, int_s *win, int *height);
void free_map(char **map, int height);

#endif /* LEVELS_H */
