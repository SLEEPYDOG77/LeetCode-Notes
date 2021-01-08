# 题目

Implement `atoi` which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found.

Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behaviour of this function.

If the first sequence of non-whitespace characters in `str` is not a valid integral number, or if no such sequence exists because either `str` is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.



# 说明

-  Only the space character `' '` is considered as whitespace character.
- Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [-2^31, 2^31-1]. If the numerical value is out of the range of representable values, INT_MAX(-2^31) or INT_MIN(2^31-1) is returned.



# 示例

### Example 1:

```
Input: "42"
Output: 42
```



### Example 2:

```
Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
```



### Example 3:

```
Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
```



### Example 4:

```
Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
```



### Example 5:

```
Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
```



# 算法





# 代码

```c++
// 【初级算法】字符串 - 字符串转换整数（atoi）

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
        int i;
        int flag = 0;
        long ans = 0;
        for (i = 0; i < n; i++) {
            if (flag == 0) {
                if (str[i] == '+') {
                    flag = 1;
                } else if (str[i] == '-') {
                    flag = -1;
                } else if (str[i] == ' ') {
                    continue;
                } else if (str[i] >= '0' && str[i] <= '9') {
                    ans = str[i] - '0';
                    flag = 1;
                } else {
                    return 0;
                }
            } else {
                if (str[i] >= '0' && str[i] <= '9') {
                    ans = ans * 10 + (str[i] - '0');
                    if (ans * flag < INT_MIN) {
                        return INT_MIN;
                    }
                    if (ans * flag > INT_MAX) {
                        return INT_MAX;
                    }
                } else if (ans != 0) {
                    break;
                } else {
                    return 0;
                }
            }
        }
        return ans * flag;
    }
};

int main() {
    Solution test;
    string str = "words and 987";
    int result = test.myAtoi(str);
    cout << "Result = " << result << endl;
    return 0;
}
```

