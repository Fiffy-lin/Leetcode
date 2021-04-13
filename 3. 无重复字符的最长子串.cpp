// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

//  

// 示例 1:

// 输入: s = "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 示例 2:

// 输入: s = "bbbbb"
// 输出: 1
// 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 示例 3:

// 输入: s = "pwwkew"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 示例 4:

// 输入: s = ""
// 输出: 0
//  

// 提示：

// 0 <= s.length <= 5 * 104
// s 由英文字母、数字、符号和空格组成

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> window;
        int begin=0,end=0,dup=0,n=s.length(),res=INT_MIN;
        if(!n) return 0;
        while(end<n){
            char c=s[end++];
            if(window[c])
                dup++;
            window[c]++;
            if(!dup)
                res=max(res,end-begin);
            while(dup){
                char c=s[begin++];
                if(window[c]>1)
                    dup--;
                window[c]--;
            }
        }
        return res;
    }
};