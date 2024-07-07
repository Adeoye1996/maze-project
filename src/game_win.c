/*
 * File: game_win.c
 * Auth: Abdulazeez Abdulrazak
 * Desc: Functions to handle win conditions and display win message.
 */

#include "maze.h"

/**
 * print_win - Print a win message when the player finishes the game
 **/
void print_win(void)
{
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("     \\  /  __   |     |\n");
    printf("      \\/  /  \\  |     |\n");
    printf("      /  |    | |     |\n");
    printf("     /    \\__/   \\___/\n\n");
    printf("\\      /\\      / ------- |\\   |\n");
    printf(" \\    /  \\    /     |    | \\  |\n");
    printf("  \\  /    \\  /      |    |  \\ |\n");
    printf("   \\/      \\/    ------- |   \\|\n");
    printf("\n\n\n\n\n\n\n\n\n\n");
}

/**
 * check_win - Check if the player has found the win spot in the maze
 * @play: Player x/y coordinate
 * @win: The x/y coordinate of the win space
 * @game_state: The game state structure to update win status
 * Return: 1 if the player has won, 0 otherwise
 */
int check_win(double_s play, int_s win, game_state_t *game_state)
{
    if ((int)play.x == win.x && (int)play.y == win.y)
    {
        game_state->win = true;
        return (1);
    }
    return (0);
}
