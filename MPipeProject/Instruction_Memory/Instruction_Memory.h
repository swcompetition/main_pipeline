#pragma once
#include <iostream>
#include <Control.h>
#include <string>
using namespace std;

#define DATA_BITS 32
#define LOOP 5

class Instruction_Memory {
private:
    string op;
    string rs;
    string rt;
    string rd;
    string shamt;
    string ff; //function field
    string add;
    bool address[32];
    Control control_class;

public:
    Instruction_Memory();
    ~Instruction_Memory();

    void seperate(string tmp);
    void print();
    string get_op();
    string get_rs();
    string get_rt();
    string get_rd();
    string get_shamt();
    string get_ff();
    string getAddress();
    void set_rs(string rs);
    void set_rt(string rt);
    void set_rd(string rd);
    void set_control(Control& ctr);

};