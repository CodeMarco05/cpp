#import <cmath>
#include <iostream>
#import <vector>

class Solution {
public:
  double findMedianSortedArray(std::vector<int> &nums1,
                               std::vector<int> &nums2) {
    double median;

    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    std::sort(nums1.begin(), nums1.end());

    int middleNumberIndex = ceil(nums1.size() / 2);

    if (nums1.size() % 2 != 0) {
      median = nums1[middleNumberIndex];
    } else {
      median = ((float)nums1[middleNumberIndex] +
                (float)nums1[middleNumberIndex - 1]) /
               2.0;
    }

    return median;
  }
};

int main() {
  std::vector<int> v = {1, 2};
  std::vector<int> v2 = {3, 4};

  Solution s = Solution();
  double median = s.findMedianSortedArray(v, v2);

  std::cout << "The median is: " << median << std::endl;

  return 0;
}
