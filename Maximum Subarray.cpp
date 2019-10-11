class Solution {
public:
    int maxSubArray(vector<int>& nums, int st, int ed) {
        if(st > ed)
            return INT_MIN;
        if(st == ed) return nums[st];
        int mid = (st + ed) / 2;
        int left = 0;
        int right = 0;
        int sum = 0;
        for(int i = mid-1; i >= st; i--) {
            sum += nums[i];
            if(sum > left) left = sum;
        }
        sum = 0;
        for(int i = mid+1; i <= ed; i++) {
            sum += nums[i];
            if(sum > right) right = sum;
        }
        int result = left + right + nums[mid];
        left = maxSubArray(nums, st, mid-1);
        right = maxSubArray(nums, mid+1, ed);
        if(left > result) result = left;
        if(right > result) result = right;
        return result;
    }
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size()-1);
    }
};