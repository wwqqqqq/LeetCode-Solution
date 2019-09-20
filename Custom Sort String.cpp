class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> rank(26, 0);
        for(int i = 0; i < S.size(); i++) {
            rank[S[i]-'a'] = i;
        }
        // sort characters in string T from small rank to high rank
        for(int i = T.size()-1; i >= 0; i--) {
            for(int j = 0; j < i; j++) {
                int c1 = T[j] - 'a';
                int c2 = T[j+1] - 'a';
                if(rank[c1] > rank[c2]) {
                    char t = T[j];
                    T[j] = T[j+1];
                    T[j+1] = t;
                }
            }
        }
        return T;
    }
};