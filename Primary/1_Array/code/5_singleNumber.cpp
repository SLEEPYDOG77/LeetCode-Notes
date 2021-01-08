#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 方法（1）
    int singleNumber_1(vector<int>& nums) {
        // 排序
        sort(nums.begin(), nums.end());

        int len = nums.size();
        int res = nums[len - 1];

        // 遍历数组 找出不重复的数
        for (int i = 0; i < len - 1; i+=2) {
            if (nums[i] != nums[i+1]) {
                res = nums[i];
                break;
            }
        }
        return res;
    }

    // 方法（2）
    int singleNumber_2(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};

int main() {
    int arr[] = {4,1,2,1,2};
    vector<int> nums(arr, arr+5);
    Solution test;
    int result = test.singleNumber_2(nums);
    cout << "Result = " << result << endl;

    return 0;
}