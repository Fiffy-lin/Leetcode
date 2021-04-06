// https://leetcode-cn.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> ans;
    void backtrace(vector<int>& nums,vector<int>& cur){
        if(nums.size()==cur.size()){
            ans.emplace_back(cur);
            return;
        }
        for(auto &x:nums){
            if(find(cur.begin(),cur.end(),x)!=cur.end())
                continue;
            cur.emplace_back(x);
            backtrace(nums,cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        backtrace(nums,cur);
        return ans;
    }
};