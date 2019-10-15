class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count = 0;
        int max = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) {
                count = 1;
                max = 1;
            }
            else if(nums[i] > nums[i-1]) {
                count++;
                if(count > max) max = count;
            }
            else count = 1;
        }
         return max;
    }
};