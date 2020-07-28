#include "DMem.h"
void DMem::write_data(int address, int value) {
    if (!ctr.getMemWrite()) {
        return;
    }
    // Insert those value to address
    map<int, int>::iterator tmp_finder = data_memory.find(address);

    if (tmp_finder != data_memory.end()) {
        tmp_finder->second = value;
        cout << "Overwrited" << endl;
    } else {
        data_memory.insert(make_pair(address, value));
    }
}


int DMem::read_data(int address) {
    if (!ctr.getMemRead()) {
        return -1;
    }
    map<int, int>::iterator tmp_finder = data_memory.find(address);

    if (tmp_finder != data_memory.end()) {
        return tmp_finder->second;
    } else {
        return -1;
    }
}

void DMem::print_all() {
    for(auto it = data_memory.cbegin(); it != data_memory.cend(); ++it) {
        cout << "Address: " << it->first << " Values: " << it->second << endl;
    }
}

void DMem::set_control(Control& c) {
    this->ctr = c;
}
