class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> occurence;
        for(int i = 0; i < arr.size(); i++) {
            int n = arr[i];
            auto iter = occurence.find(n);
            if(iter == occurence.end()) {
                occurence.insert(pair<int,int>(n, 1));
            }
            else {
                iter->second++;
            }
        }
        set<int> occur_times;
        for(auto iter = occurence.begin(); iter != occurence.end(); iter++) {
            int t = iter->second;
            if(occur_times.find(t) != occur_times.end())
                return false;
            occur_times.insert(t);
        }
        return true;
    }
};