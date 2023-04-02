/*
** EPITECH PROJECT, 2023
** method
** File description:
** class_methods
*/

#include <stdio.h>
#include "../include/cell_class.h"
#include "../include/protos.h"

void remove_border(maze_t *self, int index)
{
    self->list.array[index] = self->list.array[self->list.lenght - 1];
    self->list.lenght -= 1;
}

void add_border(maze_t *self, coords_t border)
{
    if (border.x >= 0 && border.x < self->width && border.y >= 0 && border.y < self->height) {
        if (self->maze[border.x][border.y].visited == false && self->maze[border.x][border.y].is_front == false) {
            self->maze[border.x][border.y].is_front = true;
            self->list.array[self->list.lenght] =
            self->maze[border.x][border.y];
            self->list.lenght += 1;
        }
    }
}

maze_t *maze_constructor(maze_t *maze, int row, int col)
{
    maze->width = row;
    maze->height = col;

    maze->maze = malloc(sizeof(cell_t *) * (row + 1));

    if (maze->maze == NULL)
        return NULL;

    maze->maze[row] = NULL;
    loop_maze_constructor(row, col, maze);
    maze->list.array = malloc(sizeof(cell_t) * ((row * col) / 2));

    if (maze->list.array == NULL)
        return NULL;

    maze->list.lenght = 0;
    maze->display_maze = &display_maze;
    maze->add_border = &add_border;
    maze->remove_border = &remove_border;
    return maze;
}
