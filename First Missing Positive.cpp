class Solution {
public:
    void insert(vector<pair<int,int>>& intervals, int e) {
        // intervals is sorted in ascending order
        for(int i = 0; i < intervals.size(); i++) {
            if(intervals[i].second >= e && intervals[i].first <= e) {
                return; // e has already appeared in nums
            }
            if(intervals[i].first > e) {
                if(intervals[i].first == e + 1) {
                    if(i > 0 && intervals[i-1].second + 1 == e) {
                        intervals[i-1].second = intervals[i].second;
                        intervals.erase(intervals.begin()+i);
                    }
                    else {
                        intervals[i].first = e;
                    }
                }
                else if(i > 0 && intervals[i-1].second + 1 == e) {
                    intervals[i-1].second = e;
                }
                else {
                    intervals.insert(intervals.begin()+i, pair<int,int>(e,e));
                }
                return;
            }
        }
        if(intervals.size() != 0 && e == intervals[intervals.size()-1].second + 1) {
            intervals[intervals.size()-1].second = e;
        }
        else intervals.push_back(pair<int,int>(e,e));
    }
    int firstMissingPositive(vector<int>& nums) {
        // Q1: Does the vector contain duplicate numbers
        // Q2: Does the vector contain zero or negative numbers?
        // Q3: Is there any range of the numbers or are they just 32-bit signed integer?
        // can transform it into a interval overlap problem?
        // [1,2,6]
        // [[1,2],[6,6]]
        vector<pair<int,int>> intervals;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= 0)
                continue;
            insert(intervals, nums[i]); // we should always make sure that all intervals in the vector do not overlap w/ each other
            // and they are sorted in ascending order
        }
        if(intervals.size() == 0 || intervals[0].first > 1)
            return 1;
        return intervals[0].second + 1;
    }
};