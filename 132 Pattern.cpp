class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        vector<int> min_from_st(nums.size(), nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            if(min_from_st[i-1] > nums[i]) min_from_st[i] = nums[i];
            else min_from_st[i] = min_from_st[i-1];
        }
        for(int i = nums.size() - 2; i >= 1; i--) {
            if(nums[i] <= min_from_st[i-1]) continue;
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[j] < nums[i] && nums[j] > min_from_st[i-1])
                    return true;
            }
        }
        return false;
    }
};