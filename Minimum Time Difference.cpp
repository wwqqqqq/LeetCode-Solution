class Solution {
public:
    int string2min(string str) {
        int hour = stoi(str.substr(0,2));
        int min = stoi(str.substr(3,5));
        return hour * 60 + min;
    }
    int minDifference(int t1, int t2) {
        int r1 = t2 - t1;
        r1 = (r1<0)?(-r1):r1;
        int r2 = 1440 - r1;
        return (r1<r2)?r1:r2;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time;
        for(int i=0;i<timePoints.size();i++)
            time.push_back(string2min(timePoints[i]));
        int min = 1440;
        for(int i=0;i<timePoints.size();i++) {
            for(int j=i+1;j<timePoints.size();j++) {
                int diff = minDifference(time[i],time[j]);
                if(diff < min)
                    min = diff;
                if(min==0)
                    return 0;
            }
        }
        return min;
    }
};