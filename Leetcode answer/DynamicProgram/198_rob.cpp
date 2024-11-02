#include<iostream>
#include<vector>
#include<math.h>
class Solution {
public:
    int rob(std::vector<int>& nums) {
        int n = nums.size();
        int maxnum;
        std::vector<int> earn(n);
        if (n >= 3) {
            earn[0] = nums[0];
            earn[1] = nums[1];
            earn[2] = nums[2] + nums[0];
            maxnum = std::max(earn[1], earn[2]);
        } else if (n == 2) {
            earn[0] = nums[0];
            earn[1] = nums[1];
            maxnum = std::max(earn[0], earn[1]);
        } else {
            earn[0] = nums[0];
            maxnum = nums[0];
        }
        for (int i = 3; i < n; i++) {
            earn[i] = std::max(nums[i] + earn[i - 2], nums[i] + earn[i - 3]);
            if (maxnum < earn[i]) {
                maxnum = earn[i];
            }
        }
        return maxnum;
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
