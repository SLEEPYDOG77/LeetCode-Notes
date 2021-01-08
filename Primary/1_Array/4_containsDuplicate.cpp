#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return true;
        }

        // 排序
        sort(nums.begin(), nums.end());

        // 遍历数组 查看是否存在相邻相等元素
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i+1]) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int a[] = {1,2,3,1};
    vector<int> nums(a, a+3);
    Solution test;
    bool result = test.containsDuplicate(nums);
    cout << "Result = " << result << endl;

    return 0;
}