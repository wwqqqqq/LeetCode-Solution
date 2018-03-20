class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j, size=nums.size();
        vector<int> result;
        for (i = 0; i < size - 1; i ++)
        {
            int x = target - nums[i];
            for (j = i + 1; j < size; j ++)
            {
                if (nums[j] == x)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};