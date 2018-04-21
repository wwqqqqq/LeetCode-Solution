class Solution {
public:
    vector<int> func(vector<int>&nums,int beg,int last)
    {
        vector<int> temp;
        int len=nums.size();
        if(len==0||beg>=len) return temp;
        if(nums[beg]==1)
        {
            temp=func(nums,beg+1,1);
            temp.insert(temp.begin(),1);
            return temp;
        }
        vector<vector<int>> result;
        vector<int> processed;
        for(int i=beg;i<len;i++)
        {
            //vector<int> t;
            if(nums[i]%last==0)
            {
                auto iter=processed.begin();
                for(;iter!=processed.end();iter++)
                    if(nums[i]%(*iter)==0) break;
                if(iter!=processed.end()) continue;
                processed.push_back(nums[i]);
                vector<int> t;
                t=func(nums,i+1,nums[i]);
                //if(t.size()==0) continue;
                t.insert(t.begin(),nums[i]);
                result.push_back(t);
                
            }
        }
        if(result.size()==0) return temp;
        int max=0;
        int ind=0;
        for(int i=0;i<result.size();i++)
            if(result[i].size()>max)
            {
                max=result[i].size();
                ind=i;
            }
        return result[ind];
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==0) return vector<int>();
        sort(nums.begin(),nums.end());
        return func(nums,0,1);
    }
};