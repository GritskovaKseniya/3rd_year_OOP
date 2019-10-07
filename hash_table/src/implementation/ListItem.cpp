#include <string.h>

#include "../header/ListItem.h"

ListItem::ListItem(char* name, char* value) {
    this->name = new char[strlen(name)];
    strcpy(this->name, name);

    this->value = new char[strlen(value)];
    strcpy(this->value, value);
}

ListItem::~ListItem() {
    delete[] name;
    delete[] value;
}