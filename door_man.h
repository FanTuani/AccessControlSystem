#ifndef ACCESSCONTROLSYSTEM_DOOR_MAN_H
#define ACCESSCONTROLSYSTEM_DOOR_MAN_H

void addDoor(int id, int associatedCardID);
void removeDoor(int id);
void openDoor(int doorID, int cardID);

#endif //ACCESSCONTROLSYSTEM_DOOR_MAN_H
