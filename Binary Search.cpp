class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int beg, int end) {
        if(beg == end) {
            if(nums[beg] == target)
                return beg;
            else return -1;
        }
        else if(beg > end)
            return -1;
        int mid = (beg + end) / 2;
        if(target == nums[mid])
            return mid;
        else if(target < nums[mid])
            return binarySearch(nums, target, beg, mid - 1);
        else return binarySearch(nums, target, mid + 1, end);
    }
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};