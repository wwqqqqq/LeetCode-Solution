class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> result;
        if(S.size() == 0)
            return result;
        vector<int> begin(26, -1);
        vector<int> end(26, -1);
        vector<int> sorted;
        for(int i = 0; i < S.size(); i++) {
            int e = S[i] - 'a';
            if(begin[e] == -1) {
                begin[e] = i;
                sorted.push_back(e);
            }
            end[e] = i;
        }
        int st = begin[sorted[0]];
        int ed = end[sorted[0]];
        //int count = 1;
        for(int i = 1; i < sorted.size(); i++) {
            if(begin[sorted[i]] > ed) {
                result.push_back(ed - st + 1);
                // enter next circulation
                st = begin[sorted[i]];
                ed = end[sorted[i]];
                //count++;
                continue;
            }
            if(end[sorted[i]] > ed)
                ed = end[sorted[i]];
        }
        result.push_back(ed - st + 1);
        return result;
    }
};