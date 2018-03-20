class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int i,max=0,max2=0,ind=0;
        int size=nums.size();
        for(i=0;i<size;i++)
        {
            if(nums[i]>max) 
            {
                max2=max;
                max=nums[i];
                ind=i;
            }
            else if(nums[i]>max2)
                max2=nums[i];
        }
        if(2*max2>max) return -1;
        else return ind;
    }
};