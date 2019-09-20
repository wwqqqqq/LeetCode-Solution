class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                if(max < count) max = count;
                count = 0;
            }
            else count++;
        }
        if(count > max) max = count;
        return max;
    }
};