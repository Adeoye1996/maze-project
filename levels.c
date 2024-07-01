/* levels.c */
#include "levels.h"

const char *level1[] = {
    "1111111111111111111111111",
    "1000000000000000000000001",
    "10p0300030003000300030001",
    "1000300030003000300030001",
    "1000200020002000200020001",
    "1000300030003000300030001",
    "1000300030003000300030001",
    "1000400040004000400040001",
    "1000300030003000300030001",
    "1000300030003000300030001",
    "1000500050005000500050001",
    "1000300030003000300030001",
    "1000300030003000300030001",
    "10000000000000000000000w1",
    "1111111111111111111111111"
};

const char *level2[] = {
    "11111111111111111111111",
    "100000000000000000000001",
    "10p00000000000000000000111",
    "100000000000000000000000w1",
    "11111111111111111111111111"
};

const char *level3[] = {
    "111111111111111111111111111111111",
    "100000000000000000000000000000001",
    "1000000000000000000000000000000001",
    "10000000000000000000000000000000001",
    "100000000000000000000000000000000001",
    "10000000000p00000000000000000000000w1",
    "1111111111111111111111111111111111111"
};

const char *level4[] = {
    "11111111111111111111111",
    "10000000000000000000001",
    "10p000000000000000001",
    "1000000000000000001",
    "10000000000000001",
    "100000000000001",
    "1000000000001",
    "10000000001",
    "100000001",
    "1000001",
    "10001",
    "1w1",
    "1"
};

const char *level5[] = {
    "1111111111111111",
    "10000000000000001",
    "10p00000000000001",
    "10000000000000001",
    "10000000000000001",
    "10000000000000001",
    "1111111111111001",
    "1000000000000004",
    "1001111111101",
    "100000000001",
    "10011111111",
    "1001",
    "1001",
    "1001",
    "2002",
    "22"
};

const char *level6[] = {
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
    "a00000000000000000000000000000000a",
    "a00000000000000000000000000000000a",
    "a00000000000000000000000000000000a",
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
};

const char *level7[] = {
    "11111111111111111111111111",
    "10000000000000000000000001",
    "10p00000000000000000000001",
    "10000000000000000000000001",
    "11111111113031111111111111",
    "303",
    "303",
    "303",
    "303333333333333333333",
    "300000000000000000003",
    "333333333333333333303",
    "4444444444444444444444444444404444444444444444444444444444444444444",
    "4000000000000000000000000000000000000000000400000000000000000000004",
    "4044444444444444444444444444444444444444440404444444444444444444444",
    "40000000000000004000000000000000000000000404040444",
    "44444444404444044044444444444444444444440404040004",
    "4044440400404444444444444444444400000444044444444",
    "404400040440422444404          444404400000000004",
    "40440444040042w00000444444444     404404444444444",
    "400004 4040442244440400000004     400004",
    "440444 40404      40444444404     444444",
    "404   40004      404     404",
    "404    444       404    44044444444444",
    "404              404    40000000000004",
    "404              404    44444440444404",
    "404444444444444444044444444444404  404",
    "400000000000000000000000000000004  404",
    "44444444404444444444444444444404444404",
    "40000000004                  400000004",
    "40444444444                  444444444",
    "404",
    "40444",
    "40004",
    "44444"
};

const char *level8[] = {
    "11111111111111111111111111",
    "10000000000000000000000001",
    "10p00000000000000000000001",
    "10000000000000000000000001",
    "11111111113031111111111111",
    "303",
    "303",
    "303",
    "303333333333333333333",
    "300000000000000000003",
    "333333333333333333303",
    "4444444444444444444444444444404444444444444444444444444444444444444",
    "4000000000000000000000000000000000000000000400000000000000000000004",
    "4044444444444444444444444444444444444444440404444444444444444444444",
    "40000000000000004000000000000000000000000404040444",
    "44444444404444044044444444444444444444440404040004",
    "4044440400404444444444444444444400000444044444444",
    "404400040440422444404          444404400000000004",
    "40440444040042w00000444444444     404404444444444",
    "400004 4040442244440400000004     400004",
    "440444 40404      40444444404     444444",
    "404   40004      404     404",
    "404    444       404    44044444444444",
    "404              404    40000000000004",
    "404              404    44444440444404",
    "404444444444444444044444444444404  404",
    "400000000000000000000000000000004  404",
    "44444444404444444444444444444404444404",
    "40000000004                  400000004",
    "40444444444                  444444444",
    "404",
    "40444",
    "40004",
    "44444"
};

const char **levels[] = { level1, level2, level3, level4, level5, level6, level7, level8 };
const int level_heights[] = { 15, 5, 7, 13, 17, 5, 36, 36 }; // Add the height for each level

int num_of_levels = sizeof(levels) / sizeof(levels[0]);
