#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#include "door_man.h"
#include "utils.h"
#include "records_op.h"
#include "card_man.h"
#include "resident_man.h"

#define PASSWORD "password"
int rootPermission = 0;

void displayMainMenu() {
    clearScreen();
    if(rootPermission) {
        printf("-- ADMIN --\n");
    } else {
        printf("-- GUEST --\n");
    }
    printf("1. Doors Management\n");
    printf("2. Cards Management\n");
    printf("3. Residents Management\n");
    printf("4. Open Doors\n");
    printf("5. Exit\n");

    char op;
    scanf(" %c", &op);
    getchar();
    if (rootPermission == 0 && op < '4') {
        clearScreen();
        printf("Password: ");
        char password[40];
        scanf("%s", password);
        getchar();
        if (strcmp(password, PASSWORD) == 0) {
            rootPermission = 1;
        } else {
            printf("INVALID PASSWORD\n");
            getchar();
            return;
        }
    }
    int doorID, cardID;
    switch (op) {
        case '1':
            displayDoorMan();
            break;
        case '2':
            displayCardMan();
            break;
        case '3':
            displayResidentMan();
            break;
        case '4':
            printf("door id: ");
            scanf("%d", &doorID);
            getchar();
            printf("card id: ");
            scanf("%d", &cardID);
            getchar();
            openDoor(doorID, cardID);
            break;
        case '5':
            exit(0);
        default:
            return;
    }
}

void displayDoors() {
    printf("-- Doors Information --\n");
    for (int i = 0; i < doorSize; i++) {
        printf("Door ID: %d, Associated Card ID: %d\n", doors[i].id, doors[i].card);
    }
    printf("\n");
}

void displayCards() {
    printf("-- Cards Information --\n");
    for (int i = 0; i < cardSize; i++) {
        printf("Card ID: %d, Associated Door ID: %d, Residents: ", cards[i].id, cards[i].door);
        printf("%s ", cards[i].resident);
        printf("\n");
    }
    printf("\n");
}

void displayResidents() {
    printf("-- Residents Information --\n");
    for (int i = 0; i < residentSize; i++) {
        printf("Resident Name: %s, Associated Card ID: %d\n", residents[i].name, residents[i].card);
    }
    printf("\n");
}

void displayDoorMan() {
    clearScreen();
    displayDoors();
    printf("-- Door Management --\n");
    printf("1. Add Door\n");
    printf("2. Remove Door\n");
    printf("3. Return\n");

    char op;
    scanf("%c", &op);
    getchar();

    int id, cardID;
    switch (op) {
        case '1':
            printf("ID to add: ");
            scanf("%d", &id);
            printf("Associated Card ID: ");
            scanf("%d", &cardID);
            addDoor(id, cardID);
            break;
        case '2':
            printf("ID to be removed: ");
            scanf("%d", &id);
            removeDoor(id);
            break;
        default:
            return;
    }
    getchar();
}

void displayCardMan() {
    clearScreen();
    displayCards();

    printf("-- Cards Management --\n");
    printf("1. Add Card\n");
    printf("2. Remove Card\n");
    printf("3. Return\n");

    char op;
    scanf("%c", &op);
    getchar();

    int id, doorID;
    switch (op) {
        case '1':
            printf("ID to add: ");
            scanf("%d", &id);
            printf("Associated Door ID: ");
            scanf("%d", &doorID);
            char name[30];
            printf("Associated Resident Name: ");
            scanf("%s", name);
            addCard(id, doorID, name);
            break;
        case '2':
            printf("ID to be removed: ");
            scanf("%d", &id);
            removeCard(id);
            break;
        default:
            return;
    }
    getchar();
}

void displayResidentMan() {
    clearScreen();
    displayResidents();

    printf("-- Residents Management --\n");
    printf("1. Add Resident\n");
    printf("2. Remove Resident\n");
    printf("3. Return\n");

    char op;
    scanf("%c", &op);
    getchar();

    char name[30];
    int cardID;
    switch (op) {
        case '1':
            printf("Name of Resident: ");
            scanf("%s", name);
            printf("Associated Card ID: ");
            scanf("%d", &cardID);
            addResident(name, cardID);
            break;
        case '2':
            printf("Name of Resident to remove: ");
            scanf("%s", name);
            removeResident(name);
            break;
        default:
            return;
    }
    getchar();
}
