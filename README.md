# AbstractVM

This is a simple abstract virtual machine that interpret programs written in a basic assembly language.

## ISA

### push v
Pushes the value at the top of the stack.

### pop
Unstacks the value from the top of the stack.

### dump
Displays each value of the stack, from the most recent one to the oldest one.

### assert v
Asserts that the value at the top of the stack is equal to the one passed as a paremeter for this instruction. If it is not the case, the program execution stops with an error.

### add
Unstacks the first two values of the stack, adds them together and stacks the result.

### sub
Unstacks the first two values of the stack, subtracts them, then stacks the result.

### mul
Unstacks the first two values of the stack, multiplies them, then stacks the result.

### div
Unstacks the first two values of the stack, divides them, then stacks the result.

### mod
Unstacks the first two values of the stack, calculates the modulus, then stacks the result.

### print
Printes the first value of the stack.

### exit
Terminates the execution of the current program. If this instruction does not appears while all others instruction has been processed, the execution stops with an error.
