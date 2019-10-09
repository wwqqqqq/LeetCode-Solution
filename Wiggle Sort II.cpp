class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
        vector<int> result(nums);
        sort(result.begin(), result.end());
        reverse(result.begin(), result.end());
        int mid = result.size() / 2;
        for(int i = 0; i < result.size(); i++) {
            if(i % 2 == 0) {
                nums[i] = result[i/2 + mid];
            }
            else {
                nums[i] = result[(i-1)/2];
            }
        }
    }
};