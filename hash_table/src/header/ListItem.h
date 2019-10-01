#pragma once

class ListItem
{
    public:
        ListItem(char* name, char* value);
        ~ListItem();

        char* name;
        char* value;
        ListItem* next = 0;
};