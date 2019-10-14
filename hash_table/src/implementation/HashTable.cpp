#include <string.h>
#include <iostream>

#include "../header/ATable.h"

ATable::ATable(int maxsize) {
    size = maxsize;
    data = new ListItem*[maxsize];

    for (int i = 0; i < maxsize; ++i) {
        data[i] = 0;
    }
}

ATable::~ATable() {

    for (int i = 0; i < size; ++i) {
        delete_list(data[i]);
    }

    delete[] data;
}

void ATable::add(char* name, char* value) {
    int index = hash(name);

    ListItem* current = data[index];
    ListItem* previous = 0;

    // If current cell id 0, then create new list from it and return
    if (data[index] == 0) {
        data[index] = new ListItem(name, value);
        return;
    }

    // Go over list while keys are less than given or the end of the list is found
    while (current != 0 && strcmp(current->name, name) < 0) {
        previous = current;
        current = current->next;
    }

    // If found the end of the list, then add item to it and return
    if (current == 0) {
        previous->next = new ListItem(name, value);
        return;
    }

    // If the found key is equal to given key, then don't add anything and return
    if (strcmp(current->name, name) == 0) {
        return;
    }

    
    // In other case add new item before founded
    ListItem* new_item = new ListItem(name, value);
    new_item->next = current;

    if (previous == 0) {
        data[index] = new_item;
    } else {
        previous->next = new_item;
    }
}

void ATable::remove(char* name) {
    int index = hash(name);

    ListItem* current = data[index];
    ListItem* previous = 0;
    
    while (current != 0 && strcmp(current->name, name) < 0) {
        previous = current;
        current = current->next;
    }

    if (current == 0 || strcmp(current->name, name) > 0) {
        return;
    }

    ListItem* to_delete = current;

    if (previous == 0) {
        data[index] = to_delete->next;
    } else {
        previous->next = to_delete->next;
    }

    delete to_delete;
}

void ATable::setValue(char* name, char* value) {
    int index = hash(name);
    
    ListItem* item = find(data[index], name);

    if (item != 0) {
        delete[] item->value;
        item->value = new char[strlen(value) + 1];
        strcpy(item->value, value);
    }
}

char* ATable::getValue(char* name) {
    int index = hash(name);

    ListItem* result = find(data[index], name);

    return result == 0 ? 0 : result->value;
}

void ATable::print() {

    for (int i = 0; i < size; ++i) {
        std::cout << i << ": ";

        ListItem* current = data[i];

        while (current != 0) {
            std::cout << "Key: " << current->name << " ";
            std::cout << "Value: " << current->value << "; ";

            current = current->next;
        }

        std::cout << std::endl;
    }
}

void ATable::delete_list(ListItem* list) {
    ListItem* current = list;

    while (current != 0) {
        ListItem* to_delete = current;
        current = current->next;
        delete to_delete;
    }
    
}

ListItem* ATable::find(ListItem* list, char* name) {
    ListItem* current = list;

    while (current != 0 && strcmp(current->name, name) < 0) {
        current = current->next;
    }

    if (current == 0 || strcmp(current->name, name) > 0) {
        return 0;
    }

    return current;
}
