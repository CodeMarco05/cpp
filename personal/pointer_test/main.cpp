#include <iostream>

void makeSomething(int *i);


int main() {
  int i = 0;
  
  makeSomething(&i);

  std::cout << i << '\n';

  return 0;
}

void makeSomething(int *i){
  std::cout << *i << '\n';
  (*i)++;
}
