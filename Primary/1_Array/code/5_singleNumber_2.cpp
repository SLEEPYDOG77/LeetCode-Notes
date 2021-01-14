#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    int singleNumber_3(vector<int>& nums) {
        unordered_map<int, int> m;
        int res;

        for(int x:nums) {
            auto iter = m.find(x);
            if(iter != m.end()) {
                (iter->second)++;
            } else {
                m.emplace(x, 1);
            }
        }


        for (auto iter = m.begin(); iter != m.end(); iter++) {
            if(iter->second == 1) {
                res = iter->first;
                break;
            }
        }
        return res;
    }
};

int main(){
    // int arr[] = {4,1,2,1,2};
    // vector<int> nums(arr, arr+5);
    int arr[] = {2,2,1};
    vector<int> nums(arr, arr+2);
    Solution test;
    int result = test.singleNumber_3(nums);
    cout << "Result = " << result << endl;

    return 0;
}