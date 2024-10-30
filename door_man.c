#include <stdio.h>
#include "door_man.h"
#include "records_op.h"

void addDoor(int id, int associatedCardID) {
    if (doorSize < LEN) {
        doors[doorSize].id = id;
        doors[doorSize].card = associatedCardID;
        doorSize++;
        printf("Door with ID %d added, associated Card ID %d.\n", id, associatedCardID);
    } else {
        printf("Cannot add door, maximum limit reached.\n");
    }
    getchar();
}


void removeDoor(int id) {
    for (int i = 0; i < doorSize; i++) {
        if (doors[i].id == id) {
            for (int j = i; j < doorSize - 1; j++) {
                doors[j] = doors[j + 1];
            }
            doorSize--;
            printf("Door with ID %d removed successfully.\n", id);
            return;
        }
    }
    printf("Error: Door with ID %d not found.\n", id);
    getchar();
}


void openDoor(int doorID, int cardID) {
    for (int i = 0; i < doorSize; i++) {
        if (doors[i].id == doorID && doors[i].card == cardID) {
            printf("OK: Door %d is opened with Card %d.\n", doorID, cardID);
            getchar();
            return;
        }
    }
    printf("Error: Door %d cannot be opened with Card %d.\n", doorID, cardID);
    getchar();
}