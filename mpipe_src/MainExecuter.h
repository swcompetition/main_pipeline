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
    void init() {
        int t_val = 3;
        for (int i = 0; i < 32; i++) {
            regmem_unit.set_actual_dec(i, t_val);
        }
        // Parse from I-Mem
        imem_unit.seperate(to_execute);

        // Register Unit(Parse, Forward)
        register_unit.initRegister(regmem_unit, imem_unit.get_rs(), imem_unit.get_rt(), imem_unit.get_rd());

        // ALU Operation
        alu_unit.ALU_operation(register_unit.get_rs_forward(), register_unit.get_rt_forward());

        // DMem needed

        // Write-Back(Write to RD)
        register_unit.setRDValue(alu_unit.get_ALU_result());

        // Check output
        cout << register_unit.getRDValue() << endl;
    }
};