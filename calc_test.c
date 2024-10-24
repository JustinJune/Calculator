/*
 * Program to test the calculator program 
 */
#include <stdio.h>
#include <stdbool.h>

#include "calc.h"

#define NUM_TESTS 10

struct pair{
  char* input;
  int output;
};

struct pair input_output_pairs[NUM_TESTS] = {
  {"1+1",2}, //Test Additionc 
  {"1-1",0}, //Test Subtraction
  {"2*2",4},  //Test Multiplication
  {"2/2",1}, //Test Division
  {"1+1*2",3}, //Test Order of Operations w/Multiplication and Addition
  {"1/0",0}, //Test Divide by Zero
  {"2+2/2",3}, //Test Order of Operations w/Division and Addition
  {"4-2*2",0}, //Test Order of Operations w/Multiplication and Subtraction
  {"4-2/2",3}, //Test Order of Operations w/Division and Subtraction
  {"(1+1)*2",4} //Test Parenthesis
};

// Given the index of an input-output pair, run the test on the calculator
// program. Returns true if the tests passes, false otherwise.
bool run_test(int test_num) {
  int result = calc(input_output_pairs[test_num].input);
  int expected_result = input_output_pairs[test_num].output;
  if (result == expected_result)
  {
     return true;
  }
  else
  {
    printf("Test %d failed: '%s' = %d (expected %d)\n", test_num +1, input_output_pairs[test_num].input, result, expected_result);
    return false;
  } 
}

int main(int argc, char **argv) {
  int num_passed = 0;
  for(int i = 0; i < NUM_TESTS; i++) {
    if(run_test(i))
      num_passed++;
  }
  printf("%i out of %i tests passed.\n", num_passed, NUM_TESTS);
}
