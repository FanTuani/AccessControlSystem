#include <stdio.h>
#include "utils.h"
#include "records_op.h"

Door doors[LEN];
Card cards[LEN];
Resident residents[LEN];
int doorSize = 0, cardSize = 0, residentSize = 0;

void initRecords() {
    doorSize = 0;
    cardSize = 0;
    residentSize = 0;

    FILE *doorFile = fopen(DOOR_FILE, "rb+");
    if (doorFile) {
        while (fread(&doors[doorSize], sizeof(Door), 1, doorFile) == 1) {
            doorSize++;
        }
        fclose(doorFile);
    }

    FILE *cardFile = fopen(CARD_FILE, "rb+");
    if (cardFile) {
        while (fread(&cards[cardSize], sizeof(Card), 1, cardFile) == 1) {
            cardSize++;
        }
        fclose(cardFile);
    }

    FILE *residentFile = fopen(RESIDENT_FILE, "rb+");
    if (residentFile) {
        while (fread(&residents[residentSize], sizeof(Resident), 1, residentFile) == 1) {
            residentSize++;
        }
        fclose(residentFile);
    }
}
