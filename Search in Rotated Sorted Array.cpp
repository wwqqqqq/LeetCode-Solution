class Solution {
public:
    int search(vector<int>& nums, int target, int st, int ed, int pivot) {
        if(st == ed) {
            if(nums[st] == target)
                return st;
            else return -1;
        }
        if(nums[st] > nums[ed])
            return -1;
        int mid = st + ed;
        if(st > ed)
            mid += nums.size();
        mid = (mid / 2) % (nums.size());
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target) {
            if(mid == pivot)
                return -1;
            return search(nums, target, st, (mid-1+nums.size()) % (nums.size()), pivot); // in case mid == 0
        }
        if((mid + 1) % (nums.size()) == pivot)
            return -1;
        return search(nums, target, (mid+1) % (nums.size()), ed, pivot);
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
        int st = i % (nums.size()); // in case i == nums.size()
        int ed = i - 1; // >= 0
        return search(nums, target, st, ed, st);
    }
};