class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        map<int,int> m;
        for(auto iter=nums.begin();iter!=nums.end();iter++)
        {
            if(m.find(*iter)==m.end()) m.insert(pair<int,int>(*iter,1));
            else m[*iter]++;
        }
        int beg=0;
        for(auto iter=m.begin();iter!=m.end();iter++)
        {
            int i;
            for(i=0;i<iter->second;i++)
            {
                if(nums[beg]!=iter->first) break;
                beg++;
            }
            if(i<iter->second) break;
        }
        int ed=nums.size()-1;
        auto iter=m.end();
        auto iter2=m.begin();
        iter2--;
        for(iter--;iter!=iter2;iter--)
        {
            int i;
            for(i=0;i<iter->second;i++)
            {
                if(nums[ed]!=iter->first) break;
                ed--;
            }
            if(i<iter->second) break;
        }
        if(ed>=beg)
            return ed-beg+1;
        else return 0;
    }
};