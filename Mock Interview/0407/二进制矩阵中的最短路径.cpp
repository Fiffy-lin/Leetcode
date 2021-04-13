// 给你一个 n x n 的二进制矩阵 grid 中，返回矩阵中最短 畅通路径 的长度。如果不存在这样的路径，返回 -1 。

// 二进制矩阵中的 畅通路径 是一条从 左上角 单元格（即，(0, 0)）到 右下角 单元格（即，(n - 1, n - 1)）的路径，该路径同时满足下述要求：

// 路径途经的所有单元格都的值都是 0 。
// 路径中所有相邻的单元格应当在 8 个方向之一 上连通（即，相邻两单元之间彼此不同且共享一条边或者一个角）。
// 畅通路径的长度 是该路径途经的单元格总数。

 

// 示例 1：


// 输入：grid = [[0,1],[1,0]]
// 输出：2
// 示例 2：


// 输入：grid = [[0,0,0],[1,1,0],[1,1,0]]
// 输出：4
// 示例 3：

// 输入：grid = [[1,0,0],[1,1,0],[1,1,0]]
// 输出：-1
 

// 提示：

// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] 为 0 或 1

class Solution {
public:
    int n;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n=grid.size();        
        if(grid[0][0]||grid[n-1][n-1])
            return -1;
        vector<int> X={-1,0,1,-1,1,-1,0,1};
        vector<int> Y={-1,-1,-1,0,0,1,1,1};
        vector<vector<int>> visited(n,vector<int>(n,0));
        queue<vector<int>> q;
        q.push({0,0});
        visited[0][0]=1;
        int dis=1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;++i){
                vector<int> front=q.front();
                q.pop();
                if(front[0]==n-1&&front[1]==n-1)
                    return dis;
                for(int j=0;j<8;++j){
                    int newx=front[0]+X[j];
                    int newy=front[1]+Y[j];
                    if(judge(newx,newy,visited,grid)){
                        visited[newx][newy]=1;
                        q.push({newx,newy});
                    }
                }
            }
            dis++;
        }
        return -1;
    }
    bool judge(int x,int y,vector<vector<int>> &visited,vector<vector<int>>& grid){
        if(x<0||x>=n||y<0||y>=n||visited[x][y]||grid[x][y])
            return false;
        return true;
    }
};