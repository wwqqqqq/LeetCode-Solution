class Solution {
public:
    int verify(string p, vector<vector<int>>& count) {
        for(int i = 0; i < p.size(); i++) {
            int max_len = p.size() - i;
            int ind = p[i] - 'a';
            for(int j = 0; j < max_len; j++)
                if(count[ind][j] == 0)
                    count[ind][j] = 1;
        }
        return 1;
    }
    void findSubstring(string p, vector<vector<int>>& count) {
        int beg = 0;
        for(int i = 1; i < p.size(); i++) {
            if(p[i] - p[i-1] == 1 || (p[i] == 'a' && p[i-1] == 'z'))
                continue;
            verify(p.substr(beg, i-beg), count);
            beg = i;
        }
        verify(p.substr(beg), count);
    }
    int findSubstringInWraproundString(string p) {
        vector<vector<int>> count(26, vector<int>(p.size(),0));
        findSubstring(p, count);
        int sum = 0;
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < p.size(); j++)
                sum += count[i][j];
        }
        return sum;
    }
};