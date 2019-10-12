#include <iostream>

#include "./header/ATable.h"

void add(ATable* table);
void remove(ATable* table);
void get_value(ATable* table);
void set_value(ATable* table);
void print(ATable* table);

int main() {
    int answer = -1;

    ATable* table = new ATable();

    while (answer != 0) {
        std::cout << "0 -- Exit" << std::endl;
        std::cout << "1 -- Add" << std::endl;
        std::cout << "2 -- Remove" << std::endl;
        std::cout << "3 -- Get" << std::endl;
        std::cout << "4 -- Set" << std::endl;
        std::cout << "5 -- Print" << std::endl;

        std::cin >> answer;

        switch (answer) {
            case 1:
                add(table);
                break;

            case 2:
                remove(table);
                break;
            
            case 3:
                get_value(table);
                break;
            
            case 4:
                set_value(table);
                break;
            
            case 5:
                print(table);
                break;
        
            default:
                break;
        }
    }
    
    return 0;
}

void add(ATable* table) {
    char key[100], value[100];

    std::cout << "Input key: "; std::cin >> key;
    std::cout << "Input value: "; std::cin >> value;

    table->add(key, value);
}

void remove(ATable* table) {
    char key[100];
    
    std::cout << "Input key: "; std::cin >> key;

    table->remove(key);
}

void get_value(ATable* table) {
    char key[100];

    std::cout << "Input key: "; std::cin >> key;

    char* value = table->getValue(key);

    std::cout << (value == 0 ? "NULL" : value) << std::endl;
}

void set_value(ATable* table) {
    char key[100], value[100];

    std::cout << "Input key: "; std::cin >> key;
    std::cout << "Input value: "; std::cin >> value;

    table->setValue(key, value);
}

void print(ATable* table) {
    table->print();
}
