#include "common/all.h"

// Change this one include to run another problem locally.
#include "src/problems/array/0001_two_sum.cpp"

int main() {
    Solution solution;
    std::vector<int> nums{2, 7, 11, 15};
    const std::vector<int> answer = solution.twoSum(nums, 9);

    lc::print_vector(answer, "twoSum");
    return 0;
}
