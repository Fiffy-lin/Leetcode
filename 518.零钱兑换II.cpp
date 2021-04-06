//https://leetcode-cn.com/problems/coin-change-2/

class Solution {
public:
    vector<int> dp;
    int change(int amount, vector<int>& coins) {
        dp.resize(amount+1);
        dp[0]=1;
        for(auto &coin:coins)
            for(int i=0;i<=amount;++i)
                if(i-coin>=0)
                    dp[i]+=dp[i-coin];
        return dp[amount];
    }
};