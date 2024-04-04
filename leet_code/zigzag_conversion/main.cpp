#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::string convert(std::string s, int numRows) {
    std::string result;

    if (numRows == 1) {
      return s;
    }
    std::cout << "length: " << s.length() << std::endl;
    std::cout << "divided: " << s.length() / numRows << std::endl;
    int cols = (int)((s.length() / numRows) * (1 + 1 / (numRows - 1) + 1));
    std::cout << "Rows: " << numRows << " Columns: " << cols << std::endl;

    std::vector<std::vector<char>> array(numRows, std::vector<char>(cols));

    for (int i = 0; i < cols; i++) {
      if (s.empty()) {
        break;
      }
      if ((i % (numRows - 1)) != 0) {

        array[1][i] = s[0]; // Corrected indexing
        s.erase(0, 1);

      } else {
        for (int j = 0; j < numRows; j++) {
          array[j][i] = s[0]; // Corrected indexing
          s.erase(0, 1);
        }
      }
    }

    // Print the array
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < cols; j++) {
        if (array[i][j] != 0) {
          std::cout << array[i][j];
        } else {
          std::cout << " ";
        }
      }
      std::cout << std::endl;
    }

    // form the output
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < cols; j++) {
        if (array[i][j] != 0) {
          result += array[i][j];
        }
      }
    }
    // delete all memory

    return result;
  }
};

int main() {
  Solution s;
  std::string result = s.convert("PAYPALISHIRING", 4);
  std::cout << "Result: " << result << std::endl;
  return 0;
}
