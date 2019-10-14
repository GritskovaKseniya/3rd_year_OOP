#pragma once

#include "ListItem.h"

class ATable {
    public:
        
        /**
         * Initializes empty table
         * 
         * @param maxsize size of table (NOT max number of elements)
        */
        ATable(int maxsize=100);
        
        /**
         * Initializes table and fills with the list elements
         * 
         * @param list list with data
        */
        ATable(ListItem* list): ATable() {
            while (list != 0) {
                this->add(list->name, list->value);
                list = list->next;
            }
        }

        ~ATable();
        
        /**
         * Adds new element in table if the key not exists. String will be copied
         * 
         * @param name key for add
         * @param value value for add
        */
        void add(char* name, char* value);
        
        /**
         * Removes element if the key exists
         * 
         * @param name key to delete
        */
        void remove(char* name);

        /**
         * Sets value to key if it exists
         * 
         * @param name key to change value
         * @param value new value
        */
        void setValue(char* name, char* value);
        
        /**
         * Gets value if the key exists or 0 in other case
         * 
         * @param name key to get value
         * @return value of the key or 0 if key not exists
        */
        char* getValue(char* name);
        
        /**
         * Prints all data in table in cout
        */
        void print();
    private:
        
        /**
         * Computes hash for given key
         * 
         * @param name key to compute hash 
         * @return hash of the key
        */
        int hash(char* name) {
            int sum = 0;

            for(int i = 0; name[i] != '\0'; ++i) {
                sum+=name[i];
            }

            return sum % size;
        }

        /**
         * Deletes given lists
         * 
         * @param list list to delete
        */
        void delete_list(ListItem* list);

        /**
         * Finds element by key in the list
         * Assumes that list is sortred
         * 
         * @param list list where need to find key
         * @param name key to find
         * @return ListItem with key == name or 0 if key not exists in the list
        */
        ListItem* find(ListItem* list, char* name);

        /**
         * Stores table data
        */
        ListItem** data;

        /**
         * Size of data field
        */
        int size;
};
