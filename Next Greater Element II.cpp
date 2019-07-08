class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(), -1);
        for(int i = 0; i < nums.size(); i++) {
            if(i != 0 && nums[i-1] == nums[i] && result[i-1] > nums[i]) {
                result[i] = result[i-1];
                continue;
            }
            int j;
            for(j = i + 1; j < nums.size(); j++)
                if(nums[j] > nums[i]) {
                    result[i] = nums[j];
                    break;
                }
            if(j >= nums.size()) {
                for(j = 0; j < i; j++)
                    if(nums[j] > nums[i]) {
                        result[i] = nums[j];
                        break;
                    }
            }
        }
        return result;
    }
};