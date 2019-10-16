class Solution {
public:
    bool checkSubarraySum_bf(vector<int>& nums, int k) {
        if(k == INT_MIN) {
            for(int i = 0; i < nums.size(); i++) {
                int sum = -nums[i];
                for(int j = i+1; j < nums.size(); j++) {
                    if(sum < nums[j] + INT_MIN)
                        sum -= INT_MIN;
                    sum = sum - nums[j];
                    if(sum == INT_MIN || sum == 0)
                        return true;
                }
            }
            return false;
        }
        if(k < 0) k = -k;
        for(int i = 0; i < nums.size(); i++) {
            int sum = nums[i] % k;
            for(int j = i+1; j < nums.size(); j++) {
                sum += nums[j];
                sum = sum % k;
                if(sum == 0)
                    return true;
            }
        }
        return false;
    }
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        if(k == 0) {
            for(int i = 0; i + 1 < nums.size(); i++) {
                if(nums[i] == 0 && nums[i+1] == 0)
                    return true;
            }
            return false;
        }
        else if(k < -len || k > len) {
            return checkSubarraySum_bf(nums, k);
        }
        else if(k < 0)
            k = -k;
        vector<int> count(k, 0);
        int sum = nums[0] % k;
        for(int j = 1; j < nums.size(); j++) {
            sum = (sum + nums[j]) % k;
            if(sum == 0)
                return true;
            count[sum]++;
        }
        for(int i = 1; i + 1 < nums.size(); i++) {
            int prev = nums[i-1]%k-k;
            vector<int> count_copy = count;
            for(int j = 0; j < count.size(); j++) {
                int index = (j - prev) % k;
                count[index] = count_copy[j];
            }
            count[nums[i]%k]--;
            if(count[0] > 0)
                return true;
        }
        return false;
    }
};