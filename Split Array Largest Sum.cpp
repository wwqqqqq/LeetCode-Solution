class Solution {
public:
    int res[1001][51];
    int func(vector<int>& nums, int beg, int m, int min)
    {
        if(nums.size()-beg<m) return -1;
        if(res[beg][m]!=-1) return res[beg][m];
        if(m==1)
        {
            int count=0;
            for(int i=beg;i<nums.size();i++)
                count+=nums[i];
            res[beg][m]=count;
            return count;
        }
        int count=0;
        for(int i=beg;i<nums.size();i++)
        {
            count+=nums[i];
            if(min!=-1&&count>min) break;
            int max=func(nums,i+1,m-1,min);
            if(max==-1) break;
            else if(count>max) max=count;
            if(min==-1) min=max;
            else if(max<min) 
            {
                min=max;
            }
        }
        res[beg][m]=min;
        return min;
    }
    int splitArray(vector<int>& nums, int m) {
        for(int i=0;i<nums.size();i++)
            for(int j=1;j<=m;j++)
                res[i][j]=-1;
        return func(nums,0,m,-1);
    }
};