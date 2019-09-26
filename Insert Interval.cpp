class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        for(int i = 0; i < intervals.size(); i++) {
            if(intervals[i][1] < newInterval[0])
                // no overlapping with intervals[i]
                continue;
            if(intervals[i][0] > newInterval[1]) {
                // no overlapping, newInterval should be inserted before intervals[i]
                intervals.insert(intervals.begin() + i, newInterval);
                return intervals;
            }
            if(intervals[i][0] <= newInterval[0] && intervals[i][1] >= newInterval[1]) {
                // the new interval is completely included in intervals[i]
                return intervals;
            }
            if(intervals[i][0] > newInterval[0])
                intervals[i][0] = newInterval[0];
            if(intervals[i][1] < newInterval[1])
                intervals[i][1] = newInterval[1];
            else return intervals;
            int j = i + 1;
            while(j < intervals.size() && intervals[j][0] <= intervals[i][1]) {
                if(intervals[j][1] > intervals[i][1])
                    intervals[i][1] = intervals[j][1];
                intervals.erase(intervals.begin() + j);
            }
            return intervals;
        }
        intervals.push_back(newInterval);
        return intervals;
    }
};