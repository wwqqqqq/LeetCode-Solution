class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // without divison
        // brute force
        // O(n^2)
        // just multiply all other elements for every nums[i]
        // O(n)
        vector<int> prod_before(nums.size(), 1);
        vector<int> prod_after(nums.size(), 1);
        int prod = 1;
        for(int i = 0; i < nums.size(); i++) {
            prod_before[i] = prod;
            prod *= nums[i];
        }
        prod = 1;
        for(int i = nums.size()-1; i >= 0; i--) {
            prod_after[i] = prod;
            prod *= nums[i];
        }
        vector<int> result(nums.size(), 1);
        for(int i = 0; i < result.size(); i++) {
            result[i] = prod_before[i] * prod_after[i];
        }
        return result;
    }
};