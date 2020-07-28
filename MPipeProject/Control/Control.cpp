#include "Control.h"

Control::Control(string opcode, string shamtcode, string functioncode) {
    this->function_code = functioncode;
    if (opcode.length() != 6) {
        cout << "OPCode its length should be 6." << endl;
    }

    for (int i = 0; i < OPCODE_BITS_CTR; i++) {
        opcode_bits[i] = opcode.at(i) - '0';
        if (i < SHAMT_BITS_CTR) {
            shamt_bits[i] = shamtcode.at(i) - '0';
        }
    }

    initSignal();
}

void Control::init(string opcode, string shamtcode, string functioncode) {
    shamt_signal = false;
    this->function_code = functioncode;
    if (opcode.length() != 6) {
        cout << "OPCode its length should be 6." << endl;
    }

    for (int i = 0; i < OPCODE_BITS_CTR; i++) {
        opcode_bits[i] = opcode.at(i) - '0';
        if (i < SHAMT_BITS_CTR) {
            shamt_bits[i] = shamtcode.at(i) - '0';
        }
    }

    initSignal();
}

Control::Control() {
}


void Control::sign_extend(string bits, bool* ret_value) {
    string tmp = "";
    char to_extend = bits.at(0);
    int extend_length = 32 - bits.length();
    for (int i = 0; i < extend_length; i++) {
        tmp += to_extend;
    }
    tmp += bits;
    for (int i = 0; i < 32; i++) {
        ret_value[i] = tmp.at(i) - '0';
    }
}


void Control::initSignal() {
    string opcode_str = bool_to_str(opcode_bits, OPCODE_BITS_CTR);
    for (int i = 0; i < SHAMT_BITS_CTR; i++) {
        if (shamt_bits[i] != 0) {
            cout << "Shamt detected" << endl;
            shamt_signal = true; // it is shift operation
        }
    }

    if (shamt_signal) {
        if (function_code == "000010") {
            // Its shamt-right signal
            shamt_right = true;
        } else {
            shamt_right = false;
        }
    }

    if (opcode_str == RTYPE_OP) {
        cout << "RType detected" << endl;
        reg_dest = true;
        alu_src = false;
        mem_to_reg = false;
        reg_write = true;
        mem_read = false;
        mem_write = false;
        is_branch = false;
        alu_op[0] = 1;
        alu_op[1] = 0;
    } else if (opcode_str == LW_OP) {
        cout << "LW Detected" << endl;
        shamt_signal = false;
        reg_dest = false;
        alu_src = true;
        mem_to_reg = true;
        reg_write = true;
        mem_read = true;
        mem_write = false;
        is_branch = false;
        alu_op[0] = 0;
        alu_op[1] = 0;
    } else if (opcode_str == SW_OP) {
        cout << "SW Detected" << endl;
        shamt_signal = false;
        reg_dest = false;
        alu_src = true;
        mem_to_reg = false;
        reg_write = false;
        mem_read = false;
        mem_write = true;
        is_branch = false;
        alu_op[0] = 0;
        alu_op[1] = 0;
    }
}

string Control::bool_to_str(bool* array, int size) {
    string tmp = "";
    for (int i = 0; i < size; i++) {
        tmp += (array[i] + '0');
    }
    return tmp;
}

bool Control::getBranch() {
    return this->is_branch;
}

bool Control::getRegDest() {
    return this->reg_dest;
}

bool Control::getRegWrite() {
    return this->reg_write;
}

bool Control::getAluSrc() {
    return this->alu_src;
}

bool* Control::getAluOP() {
    return this->alu_op;
}

bool Control::getMemWrite() {
    return this->mem_write;
}

bool Control::getMemRead() {
    return this->mem_read;
}

bool Control::getMemToReg() {
    return this->mem_to_reg;
}

bool Control::getShamtSignal() {
    return this->shamt_signal;
}

bool Control::getShamtRight() {
    return this->shamt_right;
}

/**
 * For converting some bits to idx value
 * binaries --> decimal
 */
int Control::conv_bin_dec_idx(bool* bits, int bitidx) {
    int ret_val = 0;

    for (int i = 0; i < bitidx; i++) {
        ret_val += pow(2, (bitidx - 1) - i) * bits[i];
    }
    return ret_val;
}

void Control::conv_dec_to_bin(int target, bool return_value[]) {
    const int max_reg = 32;
    for (int i = 0; i < max_reg; i++) {
        return_value[i] = 0;
    }
    int target_value = target; // Decimal value of register

    string tmp_str = "";
    while (target_value != 0) {
        tmp_str += (target_value % 2) + '0';
        target_value /= 2;
    }
    int str_iter = tmp_str.length() - 1;
    for (int i = 0; i < max_reg; i++) {
        if (i < max_reg - tmp_str.length()) {
            return_value[i] = 0;
        } else {
            return_value[i] = tmp_str.at(str_iter--) - '0';
        }
    }
}