class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = -1;
        for(; i < nums.size(); i++) {
            if(nums[i] == 0)
                continue;
            j++;
            if(i != j) {
                nums[j] = nums[i];
                nums[i] = 0;
            }
        }
    }
};