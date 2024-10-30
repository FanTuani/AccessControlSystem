#include <stdio.h>
#include "records_op.h"
#include "card_man.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "records_op.h"

void addCard(int id, int associatedDoorID, const char *residentName) {
    cards[cardSize].id = id;
    cards[cardSize].door = associatedDoorID;

    for (int i = 0; i < LEN; i++) {
        if (cards[cardSize].residents[i] == NULL) {
            cards[cardSize].residents[i] = malloc(strlen(residentName) + 1);
            if (cards[cardSize].residents[i] != NULL) {
                strcpy(cards[cardSize].residents[i], residentName);
            }
            break;
        }
    }

    cardSize++;
    printf("Card with ID %d added, associated Door ID %d, Resident Name: %s.\n", id, associatedDoorID, residentName);
    getchar();
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
