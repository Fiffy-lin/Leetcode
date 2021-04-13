// https://leetcode-cn.com/problems/permutation-in-string/

// 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

// 换句话说，第一个字符串的排列之一是第二个字符串的 子串 。

//  

// 示例 1：

// 输入: s1 = "ab" s2 = "eidbaooo"
// 输出: True
// 解释: s2 包含 s1 的排列之一 ("ba").
// 示例 2：

// 输入: s1= "ab" s2 = "eidboaoo"
// 输出: False
//  

// 提示：

// 输入的字符串只包含小写字母
// 两个字符串的长度都在 [1, 10,000] 之间


// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/permutation-in-string
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> need,cur;
        for (auto &x:s1)
            need[x]++;
        int b=0,e=0,n=s2.length(),valid=0;
        while(e<n){
            if(valid!=need.size()){
                char c=s2[e++];
                cur[c]++;
                if(need.count(c))
                    if(cur[c]==need[c])
                        valid++;
            }
            while(valid==need.size()){
                if(s1.length()==(e-b))
                    return true;
                char c=s2[b++];
                if(need.count(c))
                    if(cur[c]==need[c])
                        valid--;
                cur[c]--;
            }
        }
        return false;
    }
};