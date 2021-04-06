// https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution {
public:
    string removeDuplicates(string S) {
        string stk;
        for(auto &x:S){
            if(!stk.empty()&&x==stk.back())
                stk.pop_back();
            else
                stk.push_back(x);
        }
        return stk;
    }
};