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
        std::vector<vector<long>> q = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
        std::vector<vector<long>> res = pow(q,n);
        return res[0][2];
    }
    std::vector<vector<long>> pow(std::vector<vector<long>> q, long n) {
        vector<vector<long>> ret = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        while (n > 0) {
            if ((n & 1) == 1) {
                ret = multiply(ret, q);
            }
            n >>= 1;
            q = multiply(q, q);
        }
        return ret;
    }
    std::vector<vector<long>> multiply(vector<vector<long>>& a, vector<vector<long>>& b) {
        vector<vector<long>> c(3, vector<long>(3));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
            }
        }
        return c;
    }
};