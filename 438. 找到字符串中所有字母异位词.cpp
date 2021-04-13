// https://leetcode-cn.com/problems/find-all-anagrams-in-a-string

// 给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

// 字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

// 说明：

// 字母异位词指字母相同，但排列不同的字符串。
// 不考虑答案输出的顺序。
// 示例 1:

// 输入:
// s: "cbaebabacd" p: "abc"

// 输出:
// [0, 6]

// 解释:
// 起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
// 起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
//  示例 2:

// 输入:
// s: "abab" p: "ab"

// 输出:
// [0, 1, 2]

// 解释:
// 起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
// 起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
// 起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/find-all-anagrams-in-a-string
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char,int> need,cur;
        int b=0,e=0,valid=0;
        for(auto &x:p)
            need[x]++;
        int lenp=p.length();
        int lens=s.length();
        while(e<lens){
            char c=s[e++];
            if(need.count(c)){
                cur[c]++;
                if(cur[c]==need[c])
                    valid++;
            }
            while(e-b>=lenp){
                if(valid==need.size()&&(e-b)==lenp)
                    ans.emplace_back(b);
                char c=s[b++];
                if(need.count(c)){
                    if(need[c]==cur[c])
                        valid--;
                    cur[c]--;
                }
            }
        }
        return ans;
    }
};