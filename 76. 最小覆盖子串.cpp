// https://leetcode-cn.com/problems/minimum-window-substring/

// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

// 注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。

//  

// 示例 1：

// 输入：s = "ADOBECODEBANC", t = "ABC"
// 输出："BANC"
// 示例 2：

// 输入：s = "a", t = "a"
// 输出："a"
//  

// 提示：

// 1 <= s.length, t.length <= 105
// s 和 t 由英文字母组成
//  

// 进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> cur,need;
        string output=s;
        int valid=0;
        for(auto c:t)
            need[c]++;
        int start=0,end=0,left,right,len=INT_MAX;
        while(end<s.length()){
            char c=s[end++];
            if(need.count(c)){
                cur[c]++;
                if(cur[c]==need[c])
                    valid++;
            }
            while(valid==need.size()){
                if(len>(end-start)){
                    left=start;
                    len=end-start;
                }
                char d=s[start++];
                if(need.count(d)){
                    if(cur[d]==need[d])
                        valid--;
                    cur[d]--;
                }
            }
        }
        return len==INT_MAX?"":s.substr(left,len);
    }
};