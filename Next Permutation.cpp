class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // if `nums` are in decreasing order, then find the lowest possible order - reverse the vector;
        auto iter=nums.end()-1;
        for(;iter>nums.begin();iter--)
            if(*(iter-1)<*iter) break;
        if(iter==nums.begin())
        {
            for(auto iter1=nums.begin(), iter2=nums.end()-1;iter1<iter2;iter1++,iter2--)
            {
                int temp=*iter1;
                *iter1=*iter2;
                *iter2=temp;
            }
            return;
        }
        auto p = iter-1;
        for(;iter<nums.end();iter++)
            if(*iter<=*p) break;
        iter=iter-1;
        int temp=*iter;
        *iter=*p;
        *p=temp;
        for(auto iter1=p+1,iter2=nums.end()-1;iter1<iter2;iter1++,iter2--)
        {
            int temp=*iter1;
            *iter1=*iter2;
            *iter2=temp;
        }
    }
};