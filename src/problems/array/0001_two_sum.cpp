#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index_by_value;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            const int needed = target - nums[i];
            const auto found = index_by_value.find(needed);
            if (found != index_by_value.end()) {
                return {found->second, i};
            }
            index_by_value[nums[i]] = i;
        }
        return {};
    }
};
