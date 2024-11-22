#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "roomManip.h"
#include "commandParser.h"
#include "stringManip.h"

int main() {
    int dungeonSize;

    // i ask the user for its dungeon size
    printf("Enter the size of the dungeon, you can choose an integer like 4 for example: ");
    scanf("%d", &dungeonSize);
    getchar(); // Consume the leftover newline from scanf

    // Then i will make the dungeon
    ROOM *dungeon = generateDungeon(dungeonSize);
    ROOM *currentRoom = dungeon; // Start at the top left room

    printf("\nThe map of the Dungeon \n");
    printDungeon(dungeon);

    //loop
    char command[50];
    while (1) {
        printf("\nYou are in Room [%d]\n", currentRoom->data);
        printf("Available exits: ");
        displayExits(currentRoom);
        printf("Enter a command( move e,s,w,n): ");

        // Get the user command
        fgets(command, sizeof(command), stdin);
        trim(command); // Trim whitespace from the input

        // Check if the user wants to quit
        if (strcmp(command, "quit") == 0) {
            printf("Thanks for thrying  the dungeon. Goodbye!\n");
            break;
        }

        // Process the command
        ROOM *nextRoom = processCommand(command, currentRoom);
        if (nextRoom != NULL) {
            currentRoom = nextRoom; // Move to the next room
        }
    }

    // Free memory before exiting
    freeDungeon(dungeon);
    return 0;
}

