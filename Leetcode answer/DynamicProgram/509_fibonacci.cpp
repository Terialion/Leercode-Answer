#include<iostream>
#include<vector>
#include<math.h>
class Solution {
public:
    int fib(int n) {
        if (n > 2) {
            std::vector<int> temp(n, 0);
            temp[0] = 1;
            temp[1] = 1;
            for (int i = 2; i < n; i++) {
                temp[i] = temp[i - 1] + temp[i - 2];
            }
            return temp[n - 1];
        } else if (n == 1 || n == 2) {
            return 1;
        } else {
            return 0;
        }
    }
};