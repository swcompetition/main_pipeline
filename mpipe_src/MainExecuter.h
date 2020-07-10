#include "ALU.h"
#include "Instruction_Memory.h"
#include "RMem.h"
#include "Register.h"
#include "DMem.h"
class MainExecuter {
private:
    ALU alu_unit;
    Instruction_Memory imem_unit;
    RMem regmem_unit;
    Register register_unit;
    DMem datamem_unit;
    string to_execute = "00000011101000101001100100100101";
public:
    void init();
};