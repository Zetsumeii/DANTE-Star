/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include "../include/cell_class.h"
#include "../include/prims_class.h"

void add_neighbours(prims *maze, border_t *list, coords_t cell, coords_t bord)
{
    if (cell.x >= 0 && bord.x >= 0 && cell.x < maze->base.width && bord.x < maze->base.width && cell.y >= 0 && cell.y < maze->base.height && bord.y >= 0 && bord.y < maze->base.height) {
        if (maze->base.maze[bord.x][bord.y].visited == true) {
            list->array[list->lenght] = maze->base.maze[cell.x][cell.y];
            list->lenght += 1;
        }
    }
}

void neighbours_lenght_positive(prims *maze, border_t *neighbours)
{
    int random_neighbour = 0;
    if (neighbours->lenght > 0) {
        random_neighbour = rand() % neighbours->lenght;
        maze->base.maze[neighbours->array[random_neighbour].coords.x][neighbours->array[random_neighbour].coords.y].visited = true;
        maze->base.maze[neighbours->array[random_neighbour].coords.x][neighbours->array[random_neighbour].coords.y].cell_case = '*';
    }
}

void random_neighbours(prims *maze, int idx)
{
    border_t neighbours;
    neighbours.array = malloc(sizeof(cell_t) * 4);

    if (neighbours.array == NULL)
        return;
    neighbours.lenght = 0;

    coords_t tmp;
    tmp.x = maze->base.list.array[idx].coords.x;
    tmp.y = maze->base.list.array[idx].coords.y;

    add_neighbours(maze, &neighbours, (coords_t){tmp.x + 1, tmp.y}, (coords_t){tmp.x + 2, tmp.y});
    add_neighbours(maze, &neighbours, (coords_t){tmp.x - 1, tmp.y}, (coords_t){tmp.x - 2, tmp.y});
    add_neighbours(maze, &neighbours, (coords_t){tmp.x, tmp.y + 1}, (coords_t){tmp.x, tmp.y + 2});
    add_neighbours(maze, &neighbours, (coords_t){tmp.x, tmp.y - 1}, (coords_t){tmp.x, tmp.y - 2});
    neighbours_lenght_positive(maze, &neighbours);
}

void loop_maze_constructor(int row, int col, maze_t *maze)
{
    for (int i = 0; i < row; i++) {

        maze->maze[i] = malloc(sizeof(cell_t) * (col + 1));

        if (maze->maze[i] == NULL)
            return;
        maze->maze[i][col].cell_case = '\0';

        for (int j = 0; j < col; j++) {
            maze->maze[i][j].cell_case = 'X';
            maze->maze[i][j].visited = false;
            maze->maze[i][j].is_front = false;
            maze->maze[i][j].coords.x = i;
            maze->maze[i][j].coords.y = j;
        }
    }
}
