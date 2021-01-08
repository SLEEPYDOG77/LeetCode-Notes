#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        for (int i = len - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            } else {
                digits[i] = 0;
            }
        }
        vector<int> res;
        res.resize(len + 1);
        res[0] = 1;
        for (int i = 0; i < len; i++) {
            res[i + 1] = digits[i];
        }
        return res;
    }
};

int main() {
    // int a[] = {4,3,2,1};
    int a[] = {9,9,9,9};
    vector<int> digits(a, a+4);
    Solution test;
    vector<int> result = test.plusOne(digits);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\t';
    }

    return 0;
}