#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0) {
            return 0;
        }
        int profit = 0;
        for (int i = 1; i < len; i++) {
            if (prices[i] > prices[i-1]) {
                profit += (prices[i] - prices[i-1]);
            }
        }
        return profit;
    }
};

int main() {
    int arr[] = {7,1,5,3,6,4};
    vector<int> prices(arr, arr+6);
    Solution test;
    int result = test.maxProfit(prices);
    cout << "Result = " << result << endl;

    return 0;
}