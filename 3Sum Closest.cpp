class Solution {
public:
    int abs(int x) {
        return (x >= 0)? x: (-x);
    }
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3)
            return 0;
        int min = abs(nums[0] + nums[1] + nums[2] - target);
        if(min == 0) return target;
        int sum = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                int s1 = nums[i] + nums[j];
                for(int k = j+1; k < nums.size(); k++) {
                    int s = s1 + nums[k];
                    if(abs(s-target) < min) {
                        min = abs(s - target);
                        sum = s;
                    }
                    if(s > target)
                        break;
                }
            }
        }
        return sum;
    }
};