#include<iostream>
#include<vector>
#include<math.h>
class Solution {
public:
    int uniquePaths(int m, int n) {
        int array[m][n];
        array[0][0] = 0;
        if (m > 1) {
            array[1][0] = 1;
        }
        if (n > 1) {
            array[0][1] = 1;
        }
        if (m == 1 && n == 1) {
            return 1;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i + j >= 2) {
                    if (i > 0) {
                        if (j > 0) {
                            array[i][j] = array[i - 1][j] + array[i][j - 1];
                        } else {
                            array[i][j] = array[i - 1][j];
                        }
                    } else {
                        if (j > 0) {
                            array[i][j] = array[i][j - 1];
                        }
                    }
                }
            }
        }
        return array[m - 1][n - 1];
    }
};