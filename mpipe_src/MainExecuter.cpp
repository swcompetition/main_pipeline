#include "MainExecuter.h"

void MainExecuter::init() {
    int rs_idx = 29;
    int rt_idx = 2;
    regmem_unit.set_actual_dec(rs_idx, 10);
    regmem_unit.set_actual_dec(rt_idx, 20);
    // for (int i = 0; i < 32; i++) {
    //     regmem_unit.set_actual_dec(i, t_val);
    // }
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
    cout << "Final RD Value: " << register_unit.getRDValue() << endl;
}