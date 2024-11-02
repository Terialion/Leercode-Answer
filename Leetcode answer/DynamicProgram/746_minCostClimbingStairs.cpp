#include<iostream>
#include<vector>
#include<math.h>
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int cost1 = 0, cost2 = 0, next;
        for (int i = 2; i <= cost.size(); i++) {
            next = min(cost1 + cost[i - 1], cost2 + cost[i - 2]);
            cost2 = cost1;
            cost1 = next;
        }
        return cost1;
    }
};