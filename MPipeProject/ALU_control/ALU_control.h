#pragma once
#include <iostream>

using namespace std;

class ALU_control
{
private:
    string ALU_control_bit="";

public:
    ALU_control();
    ~ALU_control();
    void check_ALU_control_bit(bool* alu_op, string function_field);

    string get_ALU_control_bit();
    void set_ALU_control_bit(string temp);
};

