//https://leetcode-cn.com/problems/coin-change/

class Solution {
public:
    // int dp(vector<int>& coins,int amount){
    //     if(amount<0) return -1;
    //     if(!amount) return 0;
    //     if(res[amount-1]) return res[amount-1];
    //     int ret=INT_MAX;
    //     for(auto &x:coins){
    //         int sub=dp(coins,amount-x);
    //         if(sub>=0)
    //             ret=min(ret,1+sub);
    //     }
    //     res[amount-1]=ret==INT_MAX?-1:ret;
    //     return res[amount-1];
    // }
    // vector<int> res;
    // int coinChange(vector<int>& coins, int amount) {
    //     if(!amount) return 0;
    //     res.resize(amount);
    //     return dp(coins,amount);
    // }
    int coinChange(vector<int>& coins,int amount){
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=0;i<=amount;++i)
            for(auto coin:coins)
            {
                if(i-coin<0) continue;
                dp[i]=min(dp[i],1+dp[i-coin]); 
            }
        return dp[amount]==amount+1?-1:dp[amount];
    }
};