/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int prims_maze_generator(int row, int col, bool perfect);

int main(int argc, char *argv[])
{
    if (argc != 3)
        return 84;

    int col = atoi(argv[1]);
    int row = atoi(argv[2]);

    if (col < 0 || row < 0)
        return 84;
    return prims_maze_generator(row, col, false);
}
