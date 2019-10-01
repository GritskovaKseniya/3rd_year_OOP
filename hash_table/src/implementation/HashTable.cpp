#include <string.h>
#include <iostream>

#include "../header/HashTable.h"

ATable::ATable(int maxsize) {
    data = new ListItem*[maxsize];

    for (int i = 0; i < maxsize; ++i) {
        data[i] = 0;
    }
}

ATable::~ATable() {
    // TODO
}

int ATable::hash(char* name) {
    return strlen(name) % (sizeof(data)/sizeof(data[0]));
}

void ATable::add(char* name, char* value) {
    int index = hash(name);

    ListItem* new_item = new ListItem(name, value);

    ListItem* current = data[index];

    if (current == 0) {
        current = new_item;
    } else {
        while (current->next != 0) {
            current = current->next;
        }

        current->next = new_item;
    }
    
}

void ATable::remove(char* name) {
    int index = hash(name);

    ListItem* current = data[index];
    ListItem* previous;
    
    while (current != 0 && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == 0) {
        return;
    }

    ListItem* to_delete = current;
    previous->next = current->next;
    delete to_delete;
}

void ATable::setValue(char* name, char* value) {
    int index = hash(name);
    
    ListItem* current = data[index];

    while (current != 0 && strcmp(current->name, name) != 0) {
        current = current->next;
    }

    if (current == 0) {
        return;
    }

    current->value = value;
}

char* ATable::getValue(char* name) {
    int index = hash(name);

    ListItem* current = data[index];

    while (current != 0 && strcmp(current->name, name) != 0) {
        current = current->next;
    }

    if (current == 0) {
        return 0;
    }

    return current->value;
}

void ATable::print() {
    std:: cout << "" << std::endl;
}
