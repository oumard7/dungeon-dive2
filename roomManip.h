#ifndef ROOM_MANIP_H
#define ROOM_MANIP_H

typedef struct ROOM {
    int data;
    struct ROOM *n, *e, *s, *w; // the pointers to neighboring rooms
    int visited; // To avoid the doublefree errors
} ROOM;

ROOM *createRoom(int data);
ROOM *generateDungeon(int size);
void printDungeon(ROOM *head);
void displayExits(ROOM *room);
void freeDungeon(ROOM *room);

#endif

