class Solution {
public:
    /*int uniquePath(vector<vector<int>>& obstacleGrid, int i, int j, int m, int n)
    {
        if(obstacleGrid[i][j]==1 || i>m || j>n) return 0;
        if(i==m && j==n) return 1;
        int count=0;
        if(j+1<=n && obstacleGrid[i][j+1]==0) count+=uniquePath(obstacleGrid, i, j+1, m, n);
        if(i+1<=m && obstacleGrid[i+1][j]==0) count+=uniquePath(obstacleGrid, i+1, j, m, n);
        return count;
    }*/
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        if(m==0) return 0;
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1 || obstacleGrid[0][0]==1) return 0;
        
        int i,j;
        int res[102][102];
        for(i=0;i<=m||i<=n;i++)
        {
            res[i][n]=0;
            res[m][i]=0;
        }
        for(i=m-1;i>=0;i--)
        {
            for(j=n-1;j>=0;j--)
            {
                if(i==m-1&&j==n-1) res[i][j]=1;
                else if(obstacleGrid[i][j]==1) res[i][j]=0;
                else
                    res[i][j]=res[i+1][j]+res[i][j+1];
            }
        }
        return res[0][0];
    }
};