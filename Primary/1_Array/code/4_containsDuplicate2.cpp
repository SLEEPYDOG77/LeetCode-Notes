#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution{
public:
    bool containsDuplicate_2(vector<int>& nums) {
        unordered_set<int> s;
        for(int x : nums) {
            if (s.find(x) != s.end()) {
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};

int main(){
    int a[] = {1,2,3,1};
    vector<int> nums(a, a+4);
    Solution test;
    bool result = test.containsDuplicate_2(nums);
    cout << "Result = " << result << endl;
    return 0;
}