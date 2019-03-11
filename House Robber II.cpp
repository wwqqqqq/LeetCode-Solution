class Solution {
public:
    int max(int a, int b) {
        return (a>b)?a:b;
    }
    int rob(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        
        res[nums.size() - 1] = nums[nums.size() - 1];
        res[nums.size() - 2] = max(nums[nums.size()-1], nums[nums.size()-2]);
        for(int i = nums.size() - 3; i >= 1; i--) {
            int res1 = nums[i] + res[i+2];
            int res2 = res[i+1];
            res[i] = max(res1, res2);
        }
        
        int s1 = res[1]; // do not rob 0
        
        res[nums.size() - 1] = 0;
        res[nums.size() - 2] = nums[nums.size() - 2];
        res[nums.size() - 3] = max(nums[nums.size() - 2], nums[nums.size()-3]);
        for(int i = nums.size() - 4; i >= 2; i--) {
            int res1 = nums[i] + res[i+2];
            int res2 = res[i+1];
            res[i] = max(res1, res2);
        }
        
        int s2 = nums[0] + res[2];
        
        
        return max(s1, s2);
    }
};