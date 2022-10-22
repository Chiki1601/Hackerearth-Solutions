#include <iostream>
#include <string>
 using namespace std;
uint64_t modula_power(uint32_t base, uint32_t power, uint32_t modula_base);
 
int main() 
{
     int testcases_count;
  cin >> testcases_count;
 
  for (uint32_t testcase_index = 0; testcase_index < testcases_count; ++testcase_index) {
       int number_size  , modula_base;
    cin >> number_size >> modula_base;
 
    string number;
    cin >> number;
 
    uint64_t modula_value = 0;
    for(uint32_t digit_index = 0 ; digit_index < number_size ; ++digit_index) {
      uint8_t digit = number[digit_index] - '0';
 
      modula_value  = (modula_value + (digit * modula_power(10, number_size - digit_index - 1, modula_base)
                                             % modula_base)) % modula_base;
    }
 
    uint64_t last   = 0           ,
             answer = modula_value;
    for(uint32_t digit_index = 0 ; digit_index < number_size ; ++digit_index)
    {
      uint8_t digit = number[digit_index] - '0';
 
      modula_value  = (modula_value - (digit * modula_power(10, number_size - digit_index - 1, modula_base)
                                      ) % modula_base + modula_base) % modula_base;
 
      if (       (last + modula_value) % modula_base > answer)
        answer = (last + modula_value) % modula_base;
 
      last = (last + (digit * modula_power(10, number_size - digit_index - 2, modula_base)
                     ) % modula_base) % modula_base;
    }
 
    cout << answer << endl;
  }
}
 
uint64_t modula_power(uint32_t base, uint32_t power, uint32_t modula_base) {
  uint64_t result = 1;
 
  if (power) {
    uint64_t current = base;
    do {
      if (power % 2) // is odd
        result = (result * current) % modula_base;
 
      current = (current * current) % modula_base;
    } while (power /= 2);
  }
 
  return result;
}
