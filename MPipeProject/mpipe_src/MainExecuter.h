#include "ALU.h"
#include "Instruction_Memory.h"
#include "RMem.h"
#include "Register.h"
#include "DMem.h"
#include "Control.h"
#include "ALU_control.h"
#include "DMem.h"

class MainExecuter {
private:
    string opcode = "000000";
    Control ctr;
    ALU alu_unit;
    Instruction_Memory imem_unit;
    RMem regmem_unit;
    Register register_unit;
    DMem datamem_unit;
    ALU_control alu_control;
    /**
     * SW Test: "101011 01110 10001 0000000100101100"
     * LW Test: "100011 01110 10101 0000000100101100"
     * Add Test: "000000 10001 10001 00001 00000 100000"
     */
    //string to_execute = "10001101110101010000000100101100"; //"00000010001100010000100000100000"; //;
    DMem data_memory;
public:
    MainExecuter() {
    }
    // For now, assuming opcode is 000000
    void init(string temp);
};