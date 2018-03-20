class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        int n=grid.size();
        int temp[n*n];
        for(int i=0;i<n*n;i++)
            temp[i]=-1;
        temp[0]=grid[0][0];
        int i=0,j=0;
        map<int,int> q;
        while(i!=n-1 || j!=n-1)
        {
            if(i+1<n)
            {
                int x=(temp[n*i+j]>grid[i+1][j])?temp[n*i+j]:grid[i+1][j];
                int ind=n*(i+1)+j;
                if(temp[ind]==-1 || temp[ind]>x)
                {
                    temp[ind]=x;
                    q.insert(pair<int,int>(ind,temp[ind]));
                }
            }
            if(i-1>=0) 
            {
                int x=(temp[n*i+j]>grid[i-1][j])?temp[n*i+j]:grid[i-1][j];
                int ind=n*(i-1)+j;
                if(temp[ind]==-1 || temp[ind]>x)
                {
                    temp[ind]=x;
                    q.insert(pair<int,int>(ind,temp[ind]));
                }
            }
            if(j+1<n)
            {
                int x=(temp[n*i+j]>grid[i][j+1])?temp[n*i+j]:grid[i][j+1];
                int ind=n*i+j+1;
                if(temp[ind]==-1 || temp[ind]>x)
                {
                    temp[ind]=x;
                    q.insert(pair<int,int>(ind,temp[ind]));
                }
            }
            if(j-1>=0)
            {
                int x=(temp[n*i+j]>grid[i][j-1])?temp[n*i+j]:grid[i][j-1];
                int ind=n*i+j-1;
                if(temp[ind]==-1 || temp[ind]>x)
                {
                    temp[ind]=x;
                    q.insert(pair<int,int>(ind,temp[ind]));
                }
            }
            int min=-1;
            int key=-1;
            for(auto iter=q.begin();iter!=q.end();iter++)
            {
                if(min==-1)
                {
                    min=iter->second;
                    key=iter->first;
                }
                else if(iter->second<min)
                {
                    min=iter->second;
                    key=iter->first;
                }
            }
            if(min==-1) break;
            q.erase(key);
            i = key/n;
            j = key%n;
        }
        return temp[n*n-1];
    }
};