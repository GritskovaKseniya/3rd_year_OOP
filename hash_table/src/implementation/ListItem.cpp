#include "../header/ListItem.h"

ListItem::ListItem(char* name, char* value) {
    this->name = name;
    this->value = value;
}

ListItem::~ListItem() {
    delete name;
    delete value;
}