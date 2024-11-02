#include<iostream>
#include<vector>
#include<math.h>
class Solution {
public:
    int climbStairs1(int n) {
        std::vector<int> temp(n, 0);
        temp[0] = 1;
        temp[1] = 2;
        for (int i = 2; i < n; i++) {
            temp[i] = temp[i - 1] + temp[i - 2];
        }
        return temp[n-1];
    }
    int climbStairs2 (int n) {
        double sqrt5 = sqrt(5);//Such as Fibonacci 
        double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
        return (int)round(fibn / sqrt5);
    }
};