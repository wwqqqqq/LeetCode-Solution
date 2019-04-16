class Solution {
public:
    /*int findMaximumXOR(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int max = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                int res = nums[i] ^ nums[j];
                if(res > max) max = res;
            }
        }
        return max;
    }*/
    int findMaximumXOR1(int fixed_ind, vector<int>& candidates, vector<int>& nums) {
        int max = 0;
        for(int i = 0; i < candidates.size(); i++) {
            int ind = candidates[i];
            int res = nums[fixed_ind] ^ nums[ind];
            if(res > max) max = res;
        }
        return max;
    }
    int findMaximumXOR(vector<int>& nums) {
        //vector<vector<int>> digits(nums.size(), vector(32, 0));
        vector<vector<int>> ones(32);
        vector<vector<int>> zeros(32);
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < 32; j++) {
                int digit = (nums[i] >> j) & 1;
                if(digit == 0)
                    zeros[j].push_back(i);
                else ones[j].push_back(i);
            }
        }
        int max = 0;
        for(int i = 31; i >= 0; i--) {
            if(zeros[i].size() == 0 || ones[i].size() == 0)
                continue;
            if(zeros[i].size() < ones[i].size()) {
                max = 0;
                for(int j = 0; j < zeros[i].size(); j++) {
                    int res = findMaximumXOR1(zeros[i][j], ones[i], nums);
                    if(res > max) max = res;
                }
            }
            else {
                max = 0;
                for(int j = 0; j < ones[i].size(); j++) {
                    int res = findMaximumXOR1(ones[i][j], zeros[i], nums);
                    if(res > max) max = res;
                }
            }
            break;
        }
        return max;
    }
};