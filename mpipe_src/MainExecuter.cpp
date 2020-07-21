#include "MainExecuter.h"

void MainExecuter::init() {
    int rs_idx = 29;
    int rt_idx = 2;
    regmem_unit.set_actual_dec(rs_idx, 10);
    regmem_unit.set_actual_dec(rt_idx, 5);
    // for (int i = 0; i < 32; i++) {
    //     regmem_unit.set_actual_dec(i, t_val);
    // }
    // Parse from I-Mem
    imem_unit.seperate(to_execute);

    // Init Control Signal
    ctr.init(imem_unit.get_op(), imem_unit.get_shamt(), imem_unit.get_ff());

    // Init ALUOP Signal
    alu_control.check_ALU_control_bit(ctr.getAluOP(), imem_unit.get_ff());

    // Init Control in Register
    register_unit.setControl(ctr);
    // Register Unit(Parse, Forward)
    register_unit.initRegister(regmem_unit, imem_unit.get_rs(), imem_unit.get_rt(), imem_unit.get_rd(), imem_unit.get_shamt());

    // Init Control in ALU
    alu_unit.setControl(ctr);
    // ALU Operation
    alu_unit.ALU_operation(register_unit.get_rs_forward(), register_unit.get_rt_forward(), alu_control.get_ALU_control_bit());

    // DMem needed

    // Write-Back(Write to RD)
    register_unit.setRDValue(alu_unit.get_ALU_result());

    // Check output
    cout << "Final RD Value: " << register_unit.getRDValue() << endl;
}