#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes_1(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return;
        }
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (nums[i] == 0) {
                for (int j = i + 1; j < len; j++) {
                    nums[j-1] = nums[j];
                }
                nums[len-1] = 0;
                len--;
                continue;
            }
        }
    }

    void moveZeroes_2(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return;
        }
        int len = nums.size();
        for (int i = len - 1; i >= 0; i--) {
            if (nums[i] == 0) {
                if (i < len) {
                    for (int j = i+1; j<= len; j++) {
                        nums[j-1] = nums[j];
                    }
                    nums[len] = 0;
                }
                len--;
            }
        }
    }

    void moveZeroes_3(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return;
        }
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
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

    int a[] = {0,1,0,3,12};
    vector<int> nums(a, a+5);
    Solution test;
    test.moveZeroes_3(nums);
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << '\t';
    }

    return 0;
}