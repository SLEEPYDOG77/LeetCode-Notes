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
        res.push_back(1);
        for (int num: digits) {
            res.push_back(num);
        }
        return res;
    }
};

int main() {
    // int a[] = {4,3,2,1};
    // int a[] = {9,9,9,9};
    int a[] = {9};
    vector<int> digits(a, a+1);
    Solution test;
    vector<int> result = test.plusOne(digits);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\t';
    }
    return 0;
}