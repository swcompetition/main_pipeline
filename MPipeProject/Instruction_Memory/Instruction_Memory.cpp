#include "Instruction_Memory.h"

Instruction_Memory::Instruction_Memory() {
}

Instruction_Memory::~Instruction_Memory() {
}

void Instruction_Memory::seperate(string tmp)
{
    if (tmp.length() != DATA_BITS)return;

    this->op = tmp.substr(0, 6);
    this->rs = tmp.substr(6, 5);
    this->rt = tmp.substr(11, 5);

    int o = 0;
    for (int i = 0; i < 6; i++) { o += pow(2, 5 - i) * (op.at(i)-'0'); }

    this->add = tmp.substr(16);
    this->rd = tmp.substr(16, 5);
    this->shamt = tmp.substr(21, 5);
    this->ff = tmp.substr(26); 
   
    // if (o == 35 || o == 43) { 
    //     this->add = tmp.substr(16);
    //     this->rd = tmp.substr(16, 5);
    //     this->shamt = tmp.substr(21, 5);
    //     this->ff = tmp.substr(26); 
    // }
    // else {
    //     this->rd = tmp.substr(16, 5);
    //     this->shamt = tmp.substr(21, 5);
    //     this->ff = tmp.substr(26);
    // }


}

void Instruction_Memory::print(){
    cout << "op : " << this->op << " , rs : " << this->rs << " , rt : " << this->rt
        << " , rd : " << this->rd << " , shamt : " << this->shamt << " , fuction_field : " << this->ff << endl << "addres : " << this->add << endl;;
}

string Instruction_Memory::get_op() { return this->op; }

string Instruction_Memory::get_rs() { return this->rs; } 

string Instruction_Memory::get_rt() { return this->rt; }

string Instruction_Memory::get_rd() { return this->rd; }

string Instruction_Memory::get_shamt(){ return this->shamt; }

string Instruction_Memory::get_ff() { return this->ff; }

string Instruction_Memory::getAddress()
{
    control_class.sign_extend(add, address);
    add = control_class.bool_to_str(address, DATA_BITS);
    return add;
}

void Instruction_Memory::set_rs(string rs_c) { this->rs = rs_c; }

void Instruction_Memory::set_rt(string rt_c) { this->rt = rt_c; }

void Instruction_Memory::set_rd(string rd_c) { this->rd = rd_c; }

void Instruction_Memory::set_control(Control& ctr) { this->control_class = ctr; }
