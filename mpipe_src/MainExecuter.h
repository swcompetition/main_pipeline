#include "ALU.h"
#include "Instruction_Memory.h"
#include "RMem.h"
#include "Register.h"
#include "DMem.h"
#include "Control.h"
#include "ALU_control.h"

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
    string to_execute = "00000011101000101000000010000000";
public:
    MainExecuter() {
    }
    // For now, assuming opcode is 000000
    void init();
};