#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution{
public:
    int singleNumber_3(vector<int>& nums) {
        unordered_set<int> s;
        int res = nums[0];

        for(int x:nums) {
            if(s.find(x) == s.end()) {
                res = x;
            }
        }
        return res;
    }
};

int main(){
    int arr[] = {4,1,2,1,2};
    vector<int> nums(arr, arr+5);
    Solution test;
    int result = test.singleNumber_3(nums);
    cout << "Result = " << result << endl;

    return 0;
}