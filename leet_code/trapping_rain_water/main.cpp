
#include <algorithm>
#include <iostream>
#include <ostream>
#include <tuple>
#include <vector>
class Solution {
public:
  int trap(std::vector<int> &height) {
    int waterElements = 0;
    int highestElement = *std::max_element(height.begin(), height.end());

    for (int row = 0; row < highestElement; row++) {
      std::tuple<int, int> outerIndexes = findOuterIndexes(height, row);
      std::cout << std::get<0>(outerIndexes) << " " << std::get<1>(outerIndexes)
                << "\n";
      if (std::get<0>(outerIndexes) == std::get<1>(outerIndexes)) {
        continue;
      }

      int potentialWater =
          std::get<1>(outerIndexes) - std::get<0>(outerIndexes) - 1;

      for (int i = std::get<0>(outerIndexes) + 1; i < std::get<1>(outerIndexes);
           i++) {
        if (height[i] - row >= 1) {
          potentialWater--;
          std::cout << "i: " << i << '\n';
        }
      }
      std::cout << "Potential Water: " << potentialWater << '\n';
      waterElements += potentialWater;
    }

    return waterElements;
  }
  std::tuple<int, int> findOuterIndexes(std::vector<int> &height, int level) {
    int lower = -1;
    int higher = 0;

    for (int i = 0; i < height.size(); i++) {
      if ((height[i] - level) >= 1) {
        // set higher element
        if (i > higher) {
          higher = i;
        }

        // Set lower
        if (lower == -1) {
          lower = i;
        }
      }
    }
    return std::make_tuple(lower, higher);
  }
};

int main() {

  std::vector<int> vec{2, 3, 0, 2, 2};

  Solution s = Solution();
  int res = s.trap(vec);
  std::cout << "Result: " << res << '\n';

  return 0;
}
