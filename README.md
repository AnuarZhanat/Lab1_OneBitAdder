# Lab1_OneBitAdder

## Part1

The verilator was installed on Ubuntu.

![Alt text](images/part1.png?raw=true "Instalattion the Verilator to Ubuntu")


## Part2 and Part3

In this part I expand the testing with while loop: 

int cases = 0;
    while (cases < 1000) {
    cases++;
    design_under_test->eval();
    tfp->dump(cases);
    }
    
The random inputs were added by: 

    int x = rand()%2;
    int y = rand()%2;
    
You can see the result of "one_bit_adder.vcd" below by GTKwave.

![Alt text](images/part2.png?raw=true "The result of one_bit_adder.vcd below by GTKwave")
