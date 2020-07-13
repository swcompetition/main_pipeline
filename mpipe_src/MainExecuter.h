#include "ALU.h"
#include "Instruction_Memory.h"
#include "RMem.h"
#include "Register.h"
#include "DMem.h"
#include "Control.h"

class MainExecuter {
private:
    string opcode = "000000";
    Control ctr;
    ALU alu_unit;
    Instruction_Memory imem_unit;
    RMem regmem_unit;
    Register register_unit;
    DMem datamem_unit;
    string to_execute = "00000011101000101001100100100101";
public:
    MainExecuter() : ctr(opcode), register_unit(&ctr) {
    }
    // For now, assuming opcode is 000000
    void init();
};