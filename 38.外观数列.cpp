/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 *
 * https://leetcode.cn/problems/count-and-say/description/
 *
 * algorithms
 * Medium (60.96%)
 * Likes:    1088
 * Dislikes: 0
 * Total Accepted:    372.7K
 * Total Submissions: 611.3K
 * Testcase Example:  '1'
 *
 * 「外观数列」是一个数位字符串序列，由递归公式定义：
 * 
 * 
 * countAndSay(1) = "1"
 * countAndSay(n) 是 countAndSay(n-1) 的行程长度编码。
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 行程长度编码（RLE）是一种字符串压缩方法，其工作原理是通过将连续相同字符（重复两次或更多次）替换为字符重复次数（运行长度）和字符的串联。例如，要压缩字符串
 * "3322251" ，我们将 "33" 用 "23" 替换，将 "222" 用 "32" 替换，将 "5" 用 "15" 替换并将 "1" 用 "11"
 * 替换。因此压缩后字符串变为 "23321511"。
 * 
 * 给定一个整数 n ，返回 外观数列 的第 n 个元素。
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4
 * 
 * 输出："1211"
 * 
 * 解释：
 * 
 * countAndSay(1) = "1"
 * 
 * countAndSay(2) = "1" 的行程长度编码 = "11"
 * 
 * countAndSay(3) = "11" 的行程长度编码 = "21"
 * 
 * countAndSay(4) = "21" 的行程长度编码 = "1211"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 
 * 输出："1"
 * 
 * 解释：
 * 
 * 这是基本情况。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 30
 * 
 * 
 * 
 * 进阶：你能迭代解决该问题吗？
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1"; // 初始值为 "1"
        for (int i = 2; i <= n; i++) { // 从第2项开始生成，直到第n项
            string cur = ""; // 用于存放当前项的报数结果
            for (int j = 0; j < ans.size(); j++) { // 遍历当前的 ans 字符串
                int cnt = 1; // 计数器，统计相同字符的数量
                // 统计相同字符的数量
                while (j + 1 < ans.size() && ans[j] == ans[j + 1]) {
                    j++;
                    cnt++;
                }
                // 将计数结果和字符追加到 cur 中
                cur += to_string(cnt) + ans[j];
            }
            ans = cur; // 更新 ans 为当前项的报数结果
        }
        return ans; // 返回第n项的报数结果
    }
};

// @lc code=end

