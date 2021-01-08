#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                }
            }
        }
        return res;
    }
};

int main() {
    int a[] = {2, 7, 11, 15};
    vector<int> nums(a, a+4);
    int target = 9;
    Solution test;
    vector<int> res = test.twoSum(nums, target);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << '\t';
    }

    return 0;
}