class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        if(nums.size() < 4)
            return result;
        int last1 = nums[0] - 1;
        int last2 = last1, last3 = last1, last4 = last1;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == last1)
                continue;
            last1 = nums[i];
            last2 = last1 - 1;
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[j] == last2)
                    continue;
                last2 = nums[j];
                last3 = last2 - 1;
                int s1 = nums[i] + nums[j];
                for(int k = j+1; k < nums.size(); k++) {
                    if(nums[k] == last3)
                        continue;
                    last3 = nums[k];
                    last4 = last3 - 1;
                    int s2 = s1 + nums[k];
                    for(int m = k+1; m < nums.size(); m++) {
                        if(nums[m] == last4)
                            continue;
                        last4 = nums[m];
                        int s = s2 + nums[m];
                        if(s == target) {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[m]};
                            result.push_back(temp);
                        }
                        if(s >= target)
                            break;
                    }
                }
            }
        }
        
        return result;
    }
};