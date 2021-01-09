#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect_1(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
            return intersect_1(nums2, nums1);
        }

        unordered_map<int, int> m;
        for(int num: nums1) {
            ++m[num];
        }

        vector<int> result;
        for(int num: nums2) {
            if(m.count(num)) {
                result.push_back(num);
                --m[num];
                if(m[num] == 0) {
                    m.erase(num);
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2};
    Solution test;
    vector<int> result = test.intersect_1(nums1, nums2);
    for(int num: result) {
        cout << num << endl;
    }
    return 0;
}