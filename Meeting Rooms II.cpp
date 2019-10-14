class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // we calculate how many meetings are happening at one time
        // but only evaluate the time point where a meeting starts or ends
        map<int,int> m;
        // start -> 1
        // end -> -1
        // O(nlogn) to construct the map
        for(int i = 0; i < intervals.size(); i++) {
            auto iter = m.find(intervals[i][0]);
            if(iter != m.end()) {
                iter->second++;
                if(iter->second == 0)
                    m.erase(iter);
            }
            else m.insert(pair<int,int>(intervals[i][0], 1));
            iter = m.find(intervals[i][1]);
            if(iter != m.end()) {
                iter->second--;
                if(iter->second == 0)
                    m.erase(iter);
            }
            else m.insert(pair<int,int>(intervals[i][1], -1));
        }
        int sum = 0;
        int max = 0;
        for(auto iter=m.begin(); iter != m.end(); iter++) {
            sum += iter->second;
            if(sum > max) max = sum;
        }
        return max;
    }
};