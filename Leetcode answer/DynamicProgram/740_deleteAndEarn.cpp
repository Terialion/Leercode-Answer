#include<iostream>
#include<vector>
#include<math.h>
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int max_val;
        max_val = nums[0];
        for (auto num :nums) {
            if (num > max_val) {
                max_val = num;
            }
        }
        std::vector<int> sum(max_val + 1);
        for (auto num : nums) {
            sum[num] += num;
        }
        return rob_leetcode(sum);
    }
        int rob_leetcode(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        int first = nums[0], second = std::max(nums[0], nums[1]);
        for (int i = 2; i < size; i++) {
            int temp = second;
            second = std::max(first + nums[i], second);
            first = temp;
        }
        return second;
    }
};