#include <stdio.h>
#include "records_op.h"
#include "card_man.h"
#include "door_man.h"
#include "resident_man.h"
#include <string.h>

void addCard(int id, int associatedDoorID, const char *residentName) {
    if (cardSize >= LEN) {
        printf("Cannot add more cards, limit reached.\n");
        return;
    }

    cards[cardSize].id = id;
    cards[cardSize].door = associatedDoorID;
    strncpy(cards[cardSize].resident, residentName, LEN - 1);
    cards[cardSize].resident[LEN - 1] = '\0';

    int doorFound = 0;
    for (int i = 0; i < doorSize; i++) {
        if (doors[i].id == associatedDoorID) {
            doorFound = 1;
            break;
        }
    }

    if (!doorFound) {
        printf("Door with ID %d not found. Adding the door.\n", associatedDoorID);
        addDoor(associatedDoorID, id);
    }

    addResident(residentName, id);

    cardSize++;
    printf("Card with ID %d added, associated Door ID %d, Resident Name: %s.\n", id, associatedDoorID,
           cards[cardSize - 1].resident);
}


void removeCard(int id) {
    for (int i = 0; i < cardSize; i++) {
        if (cards[i].id == id) {
            for (int j = i; j < cardSize - 1; j++) {
                cards[j] = cards[j + 1];
            }
            cardSize--;
            printf("Card removed successfully.\n");
            return;
        }
    }
    printf("Card not found.\n");
    getchar();
}
