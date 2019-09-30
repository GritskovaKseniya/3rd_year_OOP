struct ListItem
{
    char* data;
    ListItem* next = 0;
};

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
        ListItem* data;
};