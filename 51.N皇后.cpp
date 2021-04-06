// https://leetcode-cn.com/problems/n-queens/
class Solution {
public:
    vector<vector<string>> output;
    vector<string> cur;
    void backtrace(int n,int row){
        if(row==n){
            output.emplace_back(cur);
            return;
        }
        for(int i=0;i<n;++i){
            if(judge(n,row,i)){
                cur[row][i]='Q';
                backtrace(n,row+1);
            }
            cur[row][i]='.';
        }
    }
    bool judge(int n,int row,int col){
        for(int i=0;i<row;++i)
            if(cur[i][col]=='Q')
                return false;
        for(int i=row-1,j=col-1;i>=0&&j>=0;--i,--j)
            if(cur[i][j]=='Q')
                return false;
        for(int i=row-1,j=col+1;i>=0&&j<n;--i,++j)
            if(cur[i][j]=='Q')
                return false;
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        string temp;
        for(int i=0;i<n;++i)
            temp+='.';
        for(int i=0;i<n;++i)
            cur.emplace_back(temp);
        backtrace(n,0);
        return output;
    }
};