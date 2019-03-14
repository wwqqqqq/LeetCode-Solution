class Solution {
public:
    int func(string s, string t, int s0, int t0, vector<vector<int>> &count) {
        if(t0 >= t.size())
            return 1;
        if(s0 >= s.size())
            return 0;
        if(count[s0][t0] != -1)
            return count[s0][t0];
        int c = 0;
        for(int i = s0; i < s.size(); i++) {
            if(s[i] == t[t0])
                c += func(s, t, i+1, t0+1, count);
        }
        count[s0][t0] = c;
        return c;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> count(s.size(), vector<int>(t.size(), -1));
        return func(s, t, 0, 0, count);
    }
    /*int max(int n1, int n2, int n3) {
        if(n1 > n2) {
            if(n1 > n3) return n1;
            else return n3;
        }
        else {
            if(n2 > n3) return n2;
            else return n3;
        }
        return 0;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> res(t.size(), vector<int>(s.size(), 0));
        vector<vector<float>> count(t.size(), vector<float>(s.size(), 0));
        for(int i = 0; i < s.size(); i++) {
            res[0][i] = (s[i] == t[0])? 1 : 0;
            count[0][i] = 1;
        }
        for(int i = 1; i < t.size(); i++) {
            res[i][0] = (s[0] == t[i])? 1 : 0;
            count[i][0] = 1;
        }
        for(int j = 1; j < s.size(); j++) {
            for(int i = 1; i < t.size(); i++) {
                if(t[i] == s[j])
                    res[i][j] = res[i-1][j-1] + 1;
                res[i][j] = max(res[i][j], res[i-1][j], res[i][j-1]);
                if(res[i][j] == res[i-1][j])
                    count[i][j] += count[i-1][j];
                if(res[i][j] == res[i][j-1])
                    count[i][j] += count[i][j-1];
                if(res[i][j] == res[i-1][j-1] + 1 && t[i] == s[j])
                    count[i][j] += count[i-1][j-1];
            }
        }
        int c = 0;
        for(int i = 0; i < s.size(); i++)
            if(res[t.size()-1][i] == t.size())
                c += (int)count[t.size()-1][i];
        return c;
    }*/
};