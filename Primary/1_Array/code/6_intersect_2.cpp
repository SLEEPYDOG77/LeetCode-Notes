#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect_2(vector<int>& nums1, vector<int>& nums2) {

        // 排序
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;

        int index1 = 0;
        int index2 = 0;

        while(index1 < nums1.size() && index2 < nums2.size()) {
            if(nums1[index1] < nums2[index2]) {
                index1++;
            } else if(nums1[index1] > nums2[index2]) {
                index2++;
            } else {
                result.push_back(nums1[index1]);
                index1++;
                index2++;
            }
        }
        return result;
    }    
};

int main() {
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2};
    Solution test;
    vector<int> result = test.intersect_2(nums1, nums2);
    for(int num: result) {
        cout << num << endl;
    }
    return 0;
}