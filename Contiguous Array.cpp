class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count0=0,count1=0;
        int i,len=nums.size();
        for(i=0;i<len;i++)
            if(nums[i]==0) count0++; else count1++;
        if(count0==count1) return len;
        if(count1==0||count0==0) return 0;
        int first=count1-count0;
        int max=(count1<count0)?(2*count1):(2*count0);
        for(i=len-1;i>=4;i--)
        {
            if(nums[i]==1) first--;
            else first++;
            if(i%2==1||i>max)  continue;
            if(first==0) return i;
            int t=first;
            for(int j=1;j+i-1<len;j++)
            {
                if(nums[j-1]==0) t++; else t--;
                if(nums[j+i-1]==0) t--; else t++;
                if(t==0) return i;
            }
        }
        return 2;
    }
};