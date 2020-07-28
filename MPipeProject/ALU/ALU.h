#pragma once
#include <iostream>
#include "Control.h"
using namespace std;

#define DATA_BITS 32
#define ALU_OPERATION_BITS 4

class ALU
{
private:
    bool ALU_result[DATA_BITS] = { 0 };
    bool add_one[DATA_BITS] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
    bool zero = 1;
    bool overflow = 0;
    bool shift_right = true;
    Control main_control;


public:
    ALU();
    ~ALU();
    void ALU_operation(bool data1[], bool data2[], string ALU_control);

    void add(bool data1[], bool data2[], bool flag);
    void and_operation(bool data1[], bool data2[]);
    void or_operation(bool data1[], bool data2[]);
    void invert(bool data2[]);
    void twos_complement(bool data2[]);
    void shift(bool data1[], int shamt);
    void setControl(Control& ctr);

    bool* get_ALU_result();
    bool get_zero();
    bool get_overflow();

    void set_ALU_result(bool temp[]);
    void set_zero(bool temp);
    void set_overflow(bool temp);

    void print_ALU_result();
};

