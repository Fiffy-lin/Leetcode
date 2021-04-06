// https://leetcode-cn.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top=0,bottom=n-1,left=0,right=n-1,thres=n*n,cnt=1;
        vector<vector<int>> output(n,vector<int>(n,0));
        while(cnt<=thres){
            for(int i=left;i<=right;++i)
                output[top][i]=cnt++;
            top++;
            for(int i=top;i<=bottom;++i)
                output[i][right]=cnt++;
            right--;
            for(int i=right;i>=left;--i)
                output[bottom][i]=cnt++;
            bottom--;
            for(int i=bottom;i>=top;--i)
                output[i][left]=cnt++;
            left++;
        }
        return output;
    }
};