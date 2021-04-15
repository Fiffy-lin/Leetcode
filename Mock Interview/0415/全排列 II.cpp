// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

 

// 示例 1：

// 输入：nums = [1,1,2]
// 输出：
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]
// 示例 2：

// 输入：nums = [1,2,3]
// 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

// 提示：

// 1 <= nums.length <= 8
// -10 <= nums[i] <= 10

class Solution {
public:
    vector<vector<int>> output;
    vector<int> temp;
    int n;
    void backtrace(int index,vector<int>& nums){
        if(index==n){
            vector<int> res;
            for(auto &x:temp)
                res.emplace_back(nums[x]);
            if(find(output.begin(),output.end(),res)==output.end())
                output.emplace_back(res);
            return;
        }
        for(int i=0;i<n;++i){
            if(find(temp.begin(),temp.end(),i)==temp.end()){
                temp.emplace_back(i);
                backtrace(index+1,nums);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        backtrace(0,nums);
        return output;
    }
};