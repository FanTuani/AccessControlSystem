#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include "door_man.h"
#include "utils.h"

void displayMainMenu() {
    clearScreen();
    printf("1. Doors Management\n");
    printf("2. Cards Management\n");
    printf("3. Residents Management\n");
    printf("4. Open Doors\n");
    printf("5. Exit\n");

    char op;
    scanf("%c", &op);
    getchar();
    switch (op) {
        case '1':
            displayDoorMan();
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            exit(0);
        default:
            return;
    }
}

void displayDoorMan() {
    clearScreen();
    printf("--Door Management--\n");
    printf("1. Add Door\n");
    printf("2. Remove Door\n");
    printf("3. Modify Door\n");
    printf("4. Return\n");
    char op;
    scanf("%c", &op);
    getchar();
    char id[MAX_LEN];
    switch (op) {
        case '1':
            printf("ID to add: ");
            scanf("%s", id);
            getchar();
            addDoor(id);
            break;
        case '2':
            printf("ID to be removed: ");
            scanf("%s", id);
            getchar();
            removeDoor(id);
            break;
        case '3':
            printf("ID to be modified: ");
            scanf("%s", id);
            getchar();
            printf("new ID: ");
            char newID[MAX_LEN];
            scanf("%s", newID);
            getchar();
            modifyDoor(id);
            break;
        default:
            return;
    }
    getchar();
}

void displayCardMan() {

}

void displayResidentMan() {
    
}
