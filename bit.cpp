// MODULE counter_cell(carry_in)          (it is a synchronous composition where all assignments to all modules occur simultaneosly)
// VAR
//  value : boolean;
// ASSIGN
//  init(value) := FALSE;
//  next(value) := value xor carry_in;
// DEFINE                                  (the value of carryout is given by the current values of carryin and value)
//  carry_out := value & carry_in;
// MODULE main                               (in module main, there are 3 instantiations of module counter cell)
// VAR
//  bit0 : counter_cell(TRUE);               (the first 1 bit0 has carryin of true always)
//  bit1 : counter_cell(bit0.carry_out);     (bit1 instantiates counter cell with a carryout of bit0)
//  bit2 : counter_cell(bit1.carry_out);