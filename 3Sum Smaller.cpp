class Solution {
public:
    void insert(vector<int>& v, int e) {
        ;
        // O(log(v.size()))
    }
    int numberLETarget(vector<int>& v, int target) {
        ;
        // O(log(v.size()))
    }
    int threeSumSmaller(vector<int>& nums, int target) {
        // Time complexity: O(n^2)
        vector<int> twoSums; // twoSums should be a sorted vector
        int result = 0;
        for(int i = 2; i < nums.size(); i++) {
            // find all the sums of any two elements in nums[0..i-1]
            // the time complexity of the for loop: O(i+2logi) = O(i)
            for(int j = 0; j < i-1; j++) {
                int s = nums[j] + nums[i-1];
                insert(twoSums, s);
            }
            result += numberLETarget(twoSums, target - nums[i]); // O(2logi)
        }
        return result;
    }
};