/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include <math.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int temp = x;
        long long res = 0;
        while(x){
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res == temp;
    }

    bool isPalindrome(int x) {
        if (x < 0) return false;
        int len = log10(x) + 1;
        int num = x;
        while (num) {
            int left = num / pow(10, len - 1);
            int right = num % 10;
            if (left != right) return false;
            num %= static_cast<int>(pow(10, len - 1));
            num /= 10;
            len -= 2;
        }
        return true;
    }
};
// @lc code=end

