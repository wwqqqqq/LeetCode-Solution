class Solution {
public:
    bool p1wins(vector<int>& nums, int s1, int s2, int p1)
    {
        if(nums.size()==0) return (s1>s2 || (s1==s2 && p1==0))?true:false;
        if(nums.size()==1) return (s1+nums[0]>s2 || (s1+nums[0]==s2 && p1==0))?true:false;
        //num.size()>=2
        bool res=false;
        //choose front
        int temp = *nums.begin();
        nums.erase(nums.begin());
        if(p1wins(nums,s2,s1+temp, 1-p1)==false) res = true;
        nums.insert(nums.begin(),temp);
        if(res==true) return true;
        //choose end
        temp = *(nums.end()-1);
        nums.pop_back();
        if(p1wins(nums,s2,s1+temp, 1-p1)==false) res = true;
        nums.push_back(temp);
        return res;
    }
    bool PredictTheWinner(vector<int>& nums) {
        return p1wins(nums, 0, 0, 0);
    }
};