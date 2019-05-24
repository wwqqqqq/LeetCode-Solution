class Solution {
public:
    int overlap(vector<int>& interval1, vector<int>& interval2) {
        // 0 interval1 in interval2
        // 1 interval2 in interval1
        // 2 overlap
        // 3 no overlap
        if(interval1[0] > interval2[0] && interval1[1] < interval2[1])
            return 0;
        else if(interval1[0] <= interval2[0] && interval1[1] >= interval2[1])
            return 1;
        else if(interval1[1] < interval2[0] || interval1[0] > interval2[1])
            return 3;
        return 2;
    }
    int min(int n1, int n2) {
        if(n1 < n2)
            return n1;
        return n2;
    }
    int max(int n1, int n2) {
        if(n1 < n2)
            return n2;
        return n1;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        for(int i = 0; i < intervals.size(); i++) {
            int ok = 1;
            for(int j = 0; j < result.size(); ) {
                int state = overlap(result[j], intervals[i]);
                if(state == 3) {
                    j++;
                    continue;
                }
                else if(state == 0) {
                    result.erase(result.begin() + j);
                }
                else if(state == 1) {
                    ok = 0;
                    break;
                }
                else {
                    intervals[i][0] = min(intervals[i][0], result[j][0]);
                    intervals[i][1] = max(intervals[i][1], result[j][1]);
                    result.erase(result.begin() + j);
                }
            }
            if(ok == 1)
                result.push_back(intervals[i]);
        }
        return result;
    }
};