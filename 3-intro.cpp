// MODULE main
// VAR
//  x: boolean;
//  r: boolean;
// DEFINE                      (To model such things, there is a key word DEFINE.)
//  y := !(x xor r);           (This says that the value of y would depend on the current value of x and r as follows:)
// ASSIGN
//  init(r) := FALSE;
//  next(r) := x xor r;