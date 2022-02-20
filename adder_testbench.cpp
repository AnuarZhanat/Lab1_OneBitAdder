// Verilator generated library/class.
#include "VOneBitAdder.h"

// Verilator libraries.
#include "verilated.h"
#include "verilated_vcd_c.h"

// C++ libraries.
#include <iostream>


int main()
{
    VOneBitAdder* design_under_test = new VOneBitAdder();
    
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    design_under_test->trace(tfp, 99);
    tfp->open("one_bit_adder.vcd");
    
    int cases = 0;
    
    while (cases < 1000) {
    
    // Value generator.
    int x = rand()%2;    // One bit generator
    int y = rand()%2;
    int carry_in = 0;

    // Feed data to DUT.
    design_under_test->x = x & 1;
    design_under_test->y = y & 1;
    design_under_test->carry_in = carry_in & 1;

    // Model the behavior of the DUT.
    int expected_sum = 1;
    int expected_carry_out = 0;
   
    // Simulate/evaluate/progress time.
    cases++;
    design_under_test->eval();
    tfp->dump(cases);
   
    // Compare results.
    int sum = ((int)design_under_test->sum) & 1;
    int carry_out = ((int)design_under_test->carry_out) & 1;

    bool sum_success = (sum == expected_sum);
    bool carry_out_success = (carry_out == expected_carry_out);

    if (sum_success && carry_out_success)
    {
      std::cout << "Test passed!" << std::endl;
    }
    else
    {
      std::cout << "Test failed :(" << std::endl;
      std::cout << sum << std::endl;
      std::cout << carry_out << std::endl;
    }
    }
    
    tfp->close();
 
    return 0;
}
