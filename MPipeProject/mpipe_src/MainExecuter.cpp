#include "MainExecuter.h"

void MainExecuter::init(string temp) {
    int rs_idx = 17;
    int rt_idx = 2;
    regmem_unit.set_actual_dec(rs_idx, 100);
    regmem_unit.set_actual_dec(rt_idx, 5);
    // for (int i = 0; i < 32; i++) {
    //     regmem_unit.set_actual_dec(i, t_val);
    // }
    // Parse from I-Mem
    imem_unit.seperate(temp);

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
    if (ctr.getAluSrc()) {
        // string 32-bit to bool
        bool tmp_address[32];
        string tmp_buf = imem_unit.getAddress();
        for (int i = 0; i < 32; i++) {
            tmp_address[i] = tmp_buf.at(i) - '0';
        }
        // true --> sign-extend
        alu_unit.ALU_operation(register_unit.get_rs_forward(), tmp_address, alu_control.get_ALU_control_bit());
    } else {
        // false --> rr2
        alu_unit.ALU_operation(register_unit.get_rs_forward(), register_unit.get_rt_forward(), alu_control.get_ALU_control_bit());
    }

    // Init Control in D-Mem
    data_memory.set_control(ctr);
    // Write it
    int addr_wr = ctr.conv_bin_dec_idx(alu_unit.get_ALU_result(), 32);
    int tmp_wr = ctr.conv_bin_dec_idx(register_unit.get_rt_forward(), 32);
    data_memory.write_data(addr_wr, tmp_wr);
    // Load it
    int addr = ctr.conv_bin_dec_idx(alu_unit.get_ALU_result(), 32);
    int tmp = data_memory.read_data(addr);

    // Write-Back(Write to RD)
    if (ctr.getMemToReg()) {
        register_unit.setRDValue(tmp);
    } else {
        cout << "ALU Result: " << ctr.conv_bin_dec_idx(alu_unit.get_ALU_result(), 32) << endl;
        register_unit.setRDValue(alu_unit.get_ALU_result());
    }

    // Check output
    cout << "Final RD Value: " << register_unit.getRDValue() << endl;

    // check dmem
    data_memory.print_all();
}