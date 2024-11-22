#include "commandParser.h"
#include <stdio.h>
#include <string.h>

ROOM *processCommand(char *command, ROOM *current) {
    if (strncmp(command, "move ", 5) == 0) {
        char direction = command[5];
        switch (direction) {
            case 'n':
                if (current->n) return current->n;
                printf("You hit a wall to the north.\n");
                break;
            case 'e':
                if (current->e) return current->e;
                printf("You hit a wall to the east.\n");
                break;
            case 's':
                if (current->s) return current->s;
                printf("You hit a wall to the south.\n");
                break;
            case 'w':
                if (current->w) return current->w;
                printf("You hit a wall to the west.\n");
                break;
            default:
                printf("Invalid direction.\n");
        }
    } else {
        printf("Unknown command.\n");
    }
    return NULL;
}
