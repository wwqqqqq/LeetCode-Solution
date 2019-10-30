class Solution {
public:
    int search(vector<int>& nums, int target, int st, int ed) {
        if(st == ed) {
            if(nums[st] == target)
                return st;
            else return -1;
        }
        if(st > ed)
            return -1;
        int mid = (st + ed) / 2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target) {
            return search(nums, target, st, mid-1); 
        }
        return search(nums, target, mid+1, ed);
    }
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        int i;
        for(i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i-1]) {
                // i is the smallest number in nums
                break;
            }
        }
        if(i == nums.size())
            i = 0;
        if(nums[nums.size()-1] == target)
            return nums.size()-1;
        else if(nums[nums.size()-1] < target) {
            return search(nums, target, 0, i-1);
        }
        return search(nums, target, i, nums.size()-2);
    }
};