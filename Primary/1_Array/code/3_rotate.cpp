#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void rotate_1(vector<int>&nums, int k) {
        int n = nums.size();

        // 额外存储空间 存储最后 k 个元素
        vector<int> temp(nums.end() - k, nums.end());
        
        // 前 n - k 个元素 依次后移 k 位
        for (int i = n-k; i > 0; i--) {
            nums[i+k] = nums[i];
        }

        // 再将最后 k 个元素 拼接在原数组之前
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }

    void rotate_2(vector<int>& nums, int k) {

        int len = nums.size();
        k %= len;
        if (k == 0) {
            return;
        }

        reverse(nums.begin(), nums.end() - k);  // 先反转前 n-k 个元素
        reverse(nums.end() - k, nums.end());    // 再反转后面 k 个元素
        reverse(nums.begin(), nums.end());      // 最后反转全部的元素
    }

    void rotate_3(vector<int>& nums, int k) {
        int len = nums.size();
        int temp1 = 0;  // 辅助存储变量
        int temp2 = 0;  // 辅助存储变量
        int index = 0;
        int count = 0;  // 计数，记录移动的次数

        k %= len;
        if (k == 0) {
            return;
        }

        // i 代表当前所在闭环的首元素下标
        for (int i = 0; i <= k; i++) {

            // 如果已经每个元素都移动过了，则退出循环
            if (count >= len) {
                break;
            }

            index = i;
            temp1 = nums[i];

            // 一个闭环
            while ((index + k)%len != i) {
                temp2 = nums[(index + k)% len];
                nums[(index + k)% len] = temp1;
                index = (index + k) % len;
                temp1 = temp2;
                count++;
            }
            nums[i] = temp1;
            count++;
        }
    }
};

int main() {
    int arr[] = {-1,-100,3,99};
    int k = 2;
    vector<int> nums(arr, arr+4);
    Solution test;
    test.rotate_1(nums, k);
    for(int i = 0; i < 4; i++) {
        cout << nums[i] << '\t';
    }
    cout << endl;

    return 0;
}