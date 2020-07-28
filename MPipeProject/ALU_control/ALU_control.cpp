#include "ALU_control.h"

ALU_control::ALU_control() {}
ALU_control::~ALU_control(){}

void ALU_control::check_ALU_control_bit(bool* alu_op, string function_field) {
    bool* temp = alu_op;
    if (*temp == 1) { //R-type
        if (function_field.compare("100000") == 0) { //add
            this->ALU_control_bit = "0010";
        }
        else if (function_field.compare("100010") == 0) { // subtract
            this->ALU_control_bit = "0110";
        }
        else if (function_field.compare("100100") == 0) { //AND
            this->ALU_control_bit = "0000";
        }
        else if (function_field.compare("100101") == 0) { //OR
            this->ALU_control_bit = "0001";
        }
        else if (function_field.compare("101010") == 0) { //set on less than
            this->ALU_control_bit = "0111";
        }else if (function_field.compare("000000") == 0) { //sll
            this->ALU_control_bit = "0011";
        }else if (function_field.compare("000010") == 0) { //srl
            this->ALU_control_bit = "0100";
        }else if (function_field.compare("100111") == 0) { //nor
            this->ALU_control_bit = "1100";
        }
    }
    else if (*(temp + 1) == 1) { //Branch
        this->ALU_control_bit = "0110"; //sub
    }
    else if(*(temp + 1) == 0){ //LW or SW
        this->ALU_control_bit = "0010"; //add
    }
    cout << "ALU Control BIt: " << ALU_control_bit << endl;
}

string ALU_control::get_ALU_control_bit() {
    return this->ALU_control_bit;
}
void ALU_control::set_ALU_control_bit(string temp) {
    this->ALU_control_bit = temp;
}