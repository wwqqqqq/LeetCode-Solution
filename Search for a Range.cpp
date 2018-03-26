class Solution {
public:
    void search(vector<int> &nums,int beg, int ed, int target,vector<int>&res)
    {
        if(beg>ed||(beg==ed&&nums[beg]!=target))
        {
            res.push_back(-1);
            res.push_back(-1);
            return;
        }
        else if(beg==ed)
        {
            res.push_back(beg);
            res.push_back(beg);
            return;
        }
        int half=(ed+beg)/2;
        if(nums[half]==target)
        {
            int i;
            for(i=half-1;i>=beg;i--)
                if(nums[i]!=target) break;
            res.push_back(i+1);
            for(i=half+1;i<=ed;i++)
                if(nums[i]!=target) break;
            res.push_back(i-1);
            return;
        }
        else if(nums[half]>target) search(nums,beg,half-1,target,res);
        else search(nums,half+1,ed,target,res);
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        search(nums,0,nums.size()-1,target,res);
        return res;
    }
};