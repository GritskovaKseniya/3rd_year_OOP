#pragma once

class ListItem
{
    public:

        /**
         * Initializes item with given args
         * 
         * @param name key of item
         * @param value value of item
        */
        ListItem(char* name, char* value);

        ~ListItem();

        /**
         * Key of item
        */
        char* name;

        /**
         * Value of item
        */
        char* value;

        /**
         * Pointer to next item or 0 if this item is last
        */
        ListItem* next = 0;
};