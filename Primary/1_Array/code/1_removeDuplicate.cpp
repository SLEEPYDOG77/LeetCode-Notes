#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) {
            return len;
        }

        int pre = 0;    // 用来标识当前遍历到的部分中不重复的最后一个数的下标
        int cur = 1;    // 用来遍历整个数组

        while (cur < len) {
            if (nums[pre] == nums[cur]) {
                cur++;
            } else {
                pre++;
                nums[pre] = nums[cur];
                cur++;
            }
        }
        cout << nums.size() << endl;
        return ++pre;
    }
};

int main(){
    // int arr[3] = {1,1,2};
    int arr[10] = {0,0,1,1,1,2,2,3,3,4};
    vector<int> nums(arr, arr+5);
    Solution test;
    int result = test.removeDuplicates(nums);
    cout << "Result = " << result << endl;
    for (int i = 0; i < result; i++) {
        cout << nums[i] << '\t';
    }
    return 0;
}