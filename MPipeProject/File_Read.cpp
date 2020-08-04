#include "File_Read.h"

void File_Read::file_read() {
    ifstream file("instruction.txt");
    string string_store;

    while (getline(file, string_store)) {
        cout <<"instruction: " <<string_store << endl;
        this->me.init(string_store);
        cout << endl;
    }
}