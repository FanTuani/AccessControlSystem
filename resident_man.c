#include <stdio.h>
#include <string.h>
#include "records_op.h"
#include "resident_man.h"

void addResident(const char *name, int cardID) {
    if (residentSize >= LEN) {
        printf("Cannot add more residents.\n");
        return;
    }
    strcpy(residents[residentSize].name, name);
    residents[residentSize].card = cardID;
    residentSize++;
    printf("Resident added successfully.\n");
}

void removeResident(const char *name) {
    for (int i = 0; i < residentSize; i++) {
        if (strcmp(residents[i].name, name) == 0) {
            for (int j = i; j < residentSize - 1; j++) {
                residents[j] = residents[j + 1];
            }
            residentSize--;
            printf("Resident removed successfully.\n");
            return;
        }
    }
    printf("Resident not found.\n");
    getchar();
}

void modifyResident(const char *name, int newCardID) {
    for (int i = 0; i < residentSize; i++) {
        if (strcmp(residents[i].name, name) == 0) {
            residents[i].card = newCardID;
            printf("Resident modified successfully.\n");
            return;
        }
    }
    printf("Resident not found.\n");
    getchar();
}
