// 有且仅有一次机会把数组中某一元素替换成平方，求最大连续子序列和

class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return max(nums[0],nums[0]*nums[0]);
        vector<vector<int>> dp(n,{0,0});
        dp[0][0]=nums[0];
        dp[0][1]=nums[0]*nums[0];
        int maxi=dp[0][1];
        for(int i=1;i<n;++i){
            dp[i][0]=max(dp[i-1][0]+nums[i],nums[i]);
            dp[i][1]=max(dp[i-1][1]+nums[i],max(dp[i-1][0]+nums[i]*nums[i],nums[i]*nums[i]));
            maxi=max(maxi,dp[i][1]);
        }
        return maxi;
    }
};