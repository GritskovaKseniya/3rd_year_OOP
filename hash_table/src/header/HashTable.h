#pragma once

#include "ListItem.h"

class ATable {
    public:
        ATable(int maxsize=100);
        ~ATable();
        void add(char* name, char* value);
        void remove(char* name);
        void setValue(char* name, char* value);
        char* getValue(char* name);
        void print();
    private:
        int hash(char* name) {
            int sum = 0;

            int i = 0;
            while (name[i] != '\0') {
                sum+=name[i];
                ++i;
            }

            return sum % size;
        }
        void delete_list(ListItem* list);
        ListItem* find(ListItem* list, char* name);

        ListItem** data;
        int size;
};
