class Solution {
public:
    int abs(int n) {
        if(n < 0) return (-n);
        return n;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int min = 1000001;
        int max = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > max) max = nums[i];
            if(nums[i] < min) min = nums[i];
        }
        int max_distance = max - min;
        vector<int> distance(max_distance+1, 0);
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                int d = abs(nums[i] - nums[j]);
                distance[d]++;
            }
        }
        int count = 0;
        for(int i = 0; i < distance.size(); i++) {
            count += distance[i];
            if(count >= k)
                return i;
        }
        return max_distance;
    }
};