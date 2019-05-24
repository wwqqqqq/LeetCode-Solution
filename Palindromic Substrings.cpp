class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> result(s.size(),vector<int>(s.size(), 0));
        int count = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            result[i][i] = 1;
            count++;
            if(i + 1 < s.size() && s[i] == s[i+1]) {
                result[i][i+1] = 1;
                count++;
            }
            for(int j = i + 2; j < s.size(); j++) {
                if(s[j] != s[i])
                    continue;
                if(result[i+1][j-1] == 1) {
                    result[i][j] = 1;
                    count++;
                }
            }
        }
        return count;
    }

};