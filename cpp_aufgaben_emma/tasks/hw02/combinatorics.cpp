#include "combinatorics.h"

uint64_t factorial(uint64_t val) {
  if (val == 0 || val == 1) {
    return 1;
  } else {
    return val * factorial(val - 1);
  }
}

uint64_t permutation(uint64_t val, uint64_t val2) {
  if (val < val2) {
    return 0; // Invalid input, return 0
  }
  return factorial(val) / factorial(val - val2);
}

uint64_t combination(uint64_t val, uint64_t val2) {
  if (val < val2) {
    return 0; // Invalid input, return 0
  }
  return factorial(val) / (factorial(val2) * factorial(val - val2));
}
