#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;

        int len = s.size();
        for(int i = 0; i < len/2; i++) {
            temp = s[i];
            s[i] = s[len - i - 1];
            s[len - i - 1] = temp;
        }
    }
};

int main() {
    char a[6] = {'H','a','n','n','a','h'};
    vector<char> s(a, a+6);
    Solution test;
    test.reverseString(s);
    for(char x:s) {
        cout << x << '\t';
    }
    return 0;
}