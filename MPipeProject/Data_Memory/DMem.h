#ifndef __DMEM_H__
#define __DMEM_H__

#include <iostream>
#include <map>
#include "Control.h"

using namespace std;

class DMem {
private:
    map<int, int> data_memory;
    Control ctr;

public:
    void set_control(Control& c);
    void write_data(int address, int value);
    void set_data(int address, int value) {
        data_memory.insert(make_pair(address, value));
    }
    int read_data(int address);
    void print_all();
};
#endif // __DMEM_H__