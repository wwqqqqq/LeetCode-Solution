class Solution {
public:
    int uniquePaths(int m, int n) {
        int res[101][101];
        int i,j;
        for(i=0;i<=m||i<=n;i++)
        {
            res[i][0]=0;
            res[0][i]=0;
            if(i!=0)
            {
                res[i][1]=1;
                res[1][i]=1;
            }
        }
        for(i=2;i<=m||i<=n;i++)
        {
            for(j=2;j<=i;j++)
            {
                res[i][j]=res[i-1][j]+res[i][j-1];
                res[j][i]=res[i][j];
            }
        }
        return res[m][n];
    }
};