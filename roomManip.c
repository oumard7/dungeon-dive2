
#include "roomManip.h"
#include <stdio.h>
#include <stdlib.h>

// Create a single room
ROOM *createRoom(int data) {
    ROOM *room = malloc(sizeof(ROOM));
    room->data = data;
    room->n = room->e = room->s = room->w = NULL;
    return room;
}

// Code for the 2D dungeon
ROOM *generateDungeon(int size) {
    ROOM **spine = malloc(size * sizeof(ROOM *));
    for (int i = 0; i < size; i++) {
        spine[i] = createRoom(i);
    }

    ROOM *head = spine[0];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j < size - 1) {
                spine[j]->e = spine[j + 1];
                spine[j + 1]->w = spine[j];
            }
            if (i < size - 1) {
                spine[j]->s = createRoom((i + 1) * size + j);
                spine[j]->s->n = spine[j];
            }
            spine[j] = spine[j]->s;
        }
    }

    free(spine);
    return head;
}

// Print the dungeon as a 2D grid
void printDungeon(ROOM *head) {
    ROOM *row = head;
    while (row) {
        ROOM *col = row;
        while (col) {
            printf("[%d] ", col->data);
            col = col->e;
        }
        printf("\n");
        row = row->s;
    }
}

// show exits for the current room
void displayExits(ROOM *room) {
    if (room->n) printf("North ");
    if (room->e) printf("East ");
    if (room->s) printf("South ");
    if (room->w) printf("West ");
    printf("\n");
}

// Free the entire dungeon
void freeDungeon(ROOM *room) {
    if (!room || room->visited) return;
    room->visited = 1;

    freeDungeon(room->n);
    freeDungeon(room->e);
    freeDungeon(room->s);
    freeDungeon(room->w);
    free(room);
}

