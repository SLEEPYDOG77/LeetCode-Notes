#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // 查找某数值是否在基准数组中出现
    bool hasNum(vector<int>& longArr, int num) {
        // 迭代器
        vector<int>::iterator iter = find(longArr.begin(), longArr.end(), num);
        if (iter == longArr.end()) {
            return false;
        } else {
            // 存在即从基准数组中删除
            longArr.erase(iter);
            return true;
        }
    }

    vector<int> myIntersect(vector<int>& longArr, vector<int>& shortArr) {
        vector<int> result;
        // 遍历短一些的数组，看其中有哪些数值是在基准（长）数组中出现的
        for (int i = 0; i < shortArr.size(); i++) {
            if(hasNum(longArr, shortArr[i])) {
                result.push_back(shortArr[i]);
            }
        }
        return result;
    }

public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        if (nums1.size() > nums2.size()) {
            result = myIntersect(nums1, nums2);
        } else {
            result = myIntersect(nums2, nums1);
        }
        
        return result;
    }
};

int main() {
    int a[] = {3,1,2};
    int b[] = {1,1};

    vector<int> nums1(a, a+3);
    vector<int> nums2(b, b+2);
    Solution test;
    vector<int> result = test.intersect(nums1, nums2);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}