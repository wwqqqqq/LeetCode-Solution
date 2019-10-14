class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        vector<vector<int>> sort;
        for(int i = 0; i < intervals.size(); i++) {
            int beg = 0;
            int end = sort.size()-1;
            while(beg <= end) {
                int mid = (beg + end) / 2;
                if(sort[mid][0] < intervals[i][0])
                    beg = mid+1;
                else if(sort[mid][0] == intervals[i][0])
                    return false;
                else end = mid-1;
            }
            if(beg > end)
                sort.insert(sort.begin()+beg, intervals[i]);
            // check overlap
            if(beg - 1 >= 0 && sort[beg-1][1] > sort[beg][0])
                return false;
            if(beg + 1 < sort.size() && sort[beg][1] > sort[beg+1][0])
                return false;
        }
        return true;
    }
};