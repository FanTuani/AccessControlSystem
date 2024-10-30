#ifndef ACCESSCONTROLSYSTEM_RECORDS_OP_H
#define ACCESSCONTROLSYSTEM_RECORDS_OP_H

#define DOOR_FILE "doors.dat"
#define CARD_FILE "cards.dat"
#define RESIDENT_FILE "residents.dat"
#define LEN 100

typedef struct Door {
    int id;
    int card;
} Door;

typedef struct Card {
    int id;
    int door;
    char *residents[LEN];
} Card;

typedef struct Resident {
    char name[30];
    int card;
} Resident;

extern Door doors[LEN];
extern Card cards[LEN];
extern Resident residents[LEN];
extern int doorSize, cardSize, residentSize;

void initRecords();

#endif //ACCESSCONTROLSYSTEM_RECORDS_OP_H
