#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) {
            return;
        }
        int len = nums.size();  // 标识后面为0的部分
        for(int i = len - 1; i >= 0; i--) {
            if(nums[i] == 0) {
                if(i < len) {
                    for(int j = i +1; j <= len; j++) {
                        nums[j - 1] = nums[j];
                    }
                    nums[len] = 0;
                }
                len--;
            }
        }
    }
};

int main() {
    int a[] = {0,1,0,3,11};
    vector<int> nums(a, a+5);
    // int a[] = {0,0,1};
    // vector<int> nums(a, a+3);
    Solution test;
    test.moveZeroes(nums);
    for(int x:nums) {
        cout << x << '\t';
    }
    return 0;
}