class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*//space cost = O(m+n) solution
        int m=matrix.size();
        if(m==0) return;
        int n=matrix[0].size();
        if(n==0) return;
        int row[m];
        int col[n];
        for(int i=0;i<m;i++) row[i]=0;
        for(int j=0;j<n;j++) col[j]=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i]=1;
                    col[j]=1;
                }
            }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(row[i]==1||col[j]==1)
                    matrix[i][j]=0;*/
        //constant space cost solution
        int m=matrix.size();
        if(m==0) return;
        int n=matrix[0].size();
        if(n==0) return;
        int row0=1,col0=1;
        int i,j;
        for(i=0;i<m;i++)
            if(matrix[i][0]==0)
            {
                col0=0;
                break;
            }
        for(j=0;j<n;j++)
            if(matrix[0][j]==0)
            {
                row0=0;
                break;
            }
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        for(i=1;i<m;i++)
            for(j=1;j<n;j++)
            {
                if(matrix[i][0]==0||matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }    
        if(col0==0) for(i=0;i<m;i++) matrix[i][0]=0;
        if(row0==0) for(j=0;j<n;j++) matrix[0][j]=0;
            
            
    }
};