class Solution {
public:
    int random(int st, int ed) {
        // choose a random number between st and ed
        return (rand() % (ed - st + 1)) + st;
    }
    int findKthLargest(vector<int>& nums, int st, int ed, int k) {
        int r = random(st, ed);
        int pivot = nums[r];
        nums[r] = nums[ed];
        nums[ed] = pivot;
        int i = st;
        int j = st-1;
        for(; i < ed; i++) {
            if(nums[i] <= pivot)
                continue;
            else {
                j++;
                if(j != i) {
                    int temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;
                }
            }
        }
        j++;
        nums[ed] = nums[j];
        nums[j] = pivot;
        int index = j - st + 1;
        if(index == k)
            return pivot;
        else if(index < k)
            return findKthLargest(nums, j+1, ed, k-index);
        return findKthLargest(nums, st, j-1, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size()-1, k);
    }
};