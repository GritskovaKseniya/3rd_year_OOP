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
    int data_lengtn = sizeof(data)/sizeof(data[0]);

    for (int i = 0; i < data_lengtn; ++i) {
        delete_list(data[i]);
    }

    delete[] data;
}

int ATable::hash(char* name) {
    int sum = 0;

    int i = 0;
    while (name[i] != '\0') {
        sum+=name[i];
        ++i;
    }

    return sum % (sizeof(data)/sizeof(data[0]));
}

void ATable::add(char* name, char* value) {
    int index = hash(name);

    ListItem* new_item = new ListItem(name, value);
    ListItem* current = data[index];
    ListItem* previous = data[index];

    if (current == 0) {
        current = new_item;
        return;
    }

    while (current->next != 0 && strcmp(name, current->name) < 0) {
        previous = current;
        current = current->next;
    }

    if (strcmp(current->name, name) == 0) {
        return;
    }

    previous->next = new_item;
    new_item->next = current;
}

void ATable::remove(char* name) {
    int index = hash(name);

    ListItem* current = data[index];
    ListItem* previous = current;
    
    while (current != 0 && strcmp(name, current->name) < 0) {
        previous = current;
        current = current->next;
    }

    if (current == 0 || strcmp(name, current->name) > 0) {
        return;
    }

    ListItem* to_delete = current;
    previous->next = to_delete->next;

    if (to_delete == data[index]) {
        data[index] = to_delete->next;
    }

    delete to_delete;
}

void ATable::setValue(char* name, char* value) {
    int index = hash(name);
    
    ListItem* item = find(data[index], name);

    if (item != 0) {
        item->value = value;
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
    while (list != 0) {
        ListItem* current = list;
        ListItem* previous = list;

        while (current -> next != 0) {
            previous = current;
            current = current -> next;
        }

        previous -> next = 0;
        delete current;
        current = 0;
    }
}

ListItem* ATable::find(ListItem* list, char* name) {
    ListItem* current = list;

    while (current != 0 && strcmp(name, current->name) < 0) {
        current = current->next;
    }

    if (current == 0 || strcmp(name, current->name) > 0) {
        return 0;
    }

    return current;
}