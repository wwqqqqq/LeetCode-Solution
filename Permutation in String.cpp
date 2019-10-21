class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> require(26, 0);
        for(int i = 0; i < s1.size(); i++)
            require[s1[i]-'a']++;
        vector<vector<int>> count(26, vector<int>(s2.size(), 0));
        // count[i][j] is how many times the letter 'a'+i has appeared in s2[0..j]
        for(int i = 0; i < 26; i++) {
            if(require[i] == 0)
                continue;
            int c = 0;
            for(int j = 0; j < s2.size(); j++) {
                if(s2[j] == i + 'a')
                    c++;
                count[i][j] = c;
            }
        }
        // if we want to know how many times a letter c appears between s2[i] and s2[j]
        // we just need to calculate count[c-'a'][j] - count[c-'a'][i-1]
        for(int i = 0; i + s1.size() -1 < s2.size(); i++) {
            if(require[s2[i]-'a'] == 0)
                continue;
            // now we want to know if s2[i..(i+s1.size()-1)] is a permutation of s1
            bool isPermutation = true;
            int ed = i + s1.size() - 1;
            for(int j = 0; j < 26; j++) {
                if(require[j] == 0)
                    continue;
                int count_before = (i==0)?0:count[j][i-1];
                if(require[j] != count[j][ed] - count_before) {
                    isPermutation = false;
                    break;
                }
            }
            if(isPermutation)
                return true;
        }
        return false;
    }
};