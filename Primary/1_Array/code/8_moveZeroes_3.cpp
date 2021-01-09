#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) {
            return;
        }

        int k = 0;
        for(int i = 0;i < nums.size(); i++) {
            if(nums[i] != 0) {
                nums[k] = nums[i];
                k++;
            }
        }

        while(k < nums.size()) {
            nums[k] = 0;
            k++;
        }
    }
};

int main() {
    // int a[] = {0,1,0,3,11};
    // vector<int> nums(a, a+5);
    int a[] = {0,0,1};
    vector<int> nums(a, a+3);
    Solution test;
    test.moveZeroes(nums);
    for(int x:nums) {
        cout << x << '\t';
    }
    return 0;
}