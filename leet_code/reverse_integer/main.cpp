#include <cmath>
#include <iostream>
#include <string>

class Solution {
public:
  int reverse(int x) {

    if (x == 0) {
      return 0;
    }

    std::string res = "";
    bool isNegative = x < 0;
    x = std::abs(x);

    while (x != 0) {
      res += std::to_string(x % 10);
      x /= 10;
    }
    if (isNegative) {
      res = "-" + res;
    }

    // return result as int
    try {
      return std::stoi(res);
    } catch (std::out_of_range e) {
      return 0;
    }
  }
};

int main() {
  int num = -123;
  Solution s;
  int res = s.reverse(num);
  std::cout << res << std::endl;
  return 0;
}
