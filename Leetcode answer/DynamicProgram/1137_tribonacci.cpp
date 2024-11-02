#include<iostream>
#include<vector>
#include<math.h>

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n <= 2) {
            return 1;
        }
        std::vector<std::vector<long>> q = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
        std::vector<std::vector<long>> res = pow(q,n);
        return res[0][2];
    }
    std::vector<std::vector<long>> pow(std::vector<std::vector<long>> q, long n) {
        std::vector<std::vector<long>> ret = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        while (n > 0) {
            if ((n & 1) == 1) {
                ret = multiply(ret, q);
            }
            n >>= 1;
            q = multiply(q, q);
        }
        return ret;
    }
    std::vector<std::vector<long>> multiply(std::vector<std::vector<long>>& a, std::vector<std::vector<long>>& b) {
        std::vector<std::vector<long>> c(3, std::vector<long>(3));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
            }
        }
        return c;
    }
};