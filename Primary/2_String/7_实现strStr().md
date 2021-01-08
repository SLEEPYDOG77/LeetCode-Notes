# 题目

Implement `strStr()`.

Return the index of the first occurrence of needle in haystack, or `-1` if needle is not part of haystack.



# 示例

### Example 1:

```
Input: haystack = "hello", needle = "ll"
Output: 2
```



### Example 2:

```
Input: haystack = "aaaaa", needle = "bba"
Output: -1
```



# 说明

What should we return when `needle` is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when `needle` is an empty string. This is consistent to C's `strstr()` and Java's `indexOf()`.



# 算法





# 代码

```c++

// 【初级算法】字符串 - 实现strStr()

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int length = haystack.length();
        int length_s = needle.length();
        int i,j;
        if (length < length_s) {
            return -1;
        }
        
        for (i = 0; i <= length - length_s; i++) {
            if (haystack[i] == needle[0]) {
                for (j = 1; j < length_s; j++) {
                    if (haystack[i+j] == needle[j]) {
                        continue;
                    } else {
                        break;
                    }
                }
                if (j == length_s) {
                    return i;
                }
            }
        }
        return -1;
    }
};

int main() {
    string haystack = "hello";
    string needle = "ll";

    Solution test;
    int result = test.strStr(haystack, needle);
    cout << "Result = " << result << endl;
}
```

