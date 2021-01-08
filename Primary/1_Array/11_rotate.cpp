#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();

        if (n <= 1) {
            return;
        }

        // 四个数一组成为一个闭环 顺时针交换
        int count = n * n / 4;
        int x = 0;
        int y = 0;
        int z = 0;

        int x1, y1, x2, y2;
        // 确认每组的起始元素
        for (int i = 0; i < count; i++) {
            if (z >= (n-1) - 2 * x) {
                x += 1;
                z = 0;
            }

            y = z + x;
            z += 1;
            x1 = x;
            y1 = y;

            // 交换一组
            for (int j = 0; j < 3; j++) {
                x2 = n - 1 - y1;
                y2 = x1;

                matrix[x1][y1] = matrix[x1][y1] ^ matrix[x2][y2];
                matrix[x2][y2] = matrix[x1][y1] ^ matrix[x2][y2];
                matrix[x1][y1] = matrix[x1][y1] ^ matrix[x2][y2];

                x1 = x2;
                y1 = y2;
            }
        }
    }
};

int main() {

    Solution test;
    vector<vector<int> > matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    test.rotate(matrix);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}