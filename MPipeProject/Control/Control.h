#pragma once
#include <iostream>
#include <cmath>

using namespace std;

#define OPCODE_BITS_CTR 6
#define ALU_OP_BITS 2
#define SHAMT_BITS_CTR 5

#define RTYPE_OP "000000"
#define LW_OP "100011"
#define SW_OP "101011"
#define BEQ_OP "000100"

class Control {
private:
    bool opcode_bits[OPCODE_BITS_CTR];
    bool shamt_bits[SHAMT_BITS_CTR];
    string function_code;
    bool is_branch;
    bool reg_dest;
    bool reg_write;
    bool alu_src;
    bool alu_op[ALU_OP_BITS];
    bool mem_write;
    bool mem_read;
    bool mem_to_reg;
    bool shamt_signal;
    bool shamt_right;
    void initSignal();

public:
    Control(string opcode, string shamtcode, string functioncode);
    Control();
    void init(string opcode, string shamtcode, string functioncode);
    bool getBranch();
    bool getRegDest();
    bool getRegWrite();
    bool getAluSrc();
    bool* getAluOP();
    bool getMemWrite();
    bool getMemRead();
    bool getMemToReg();
    bool getShamtSignal();
    bool getShamtRight();
    void sign_extend(string bits, bool* ret_value);
    int conv_bin_dec_idx(bool* bits, int bitidx);
    void conv_dec_to_bin(int target, bool return_value[]);
    string bool_to_str(bool* array, int size);
};