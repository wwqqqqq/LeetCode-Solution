class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size() == 0)
            return word2.size();
        else if(word2.size() == 0)
            return word1.size();
        vector<vector<int>> map(word1.size(), vector<int>(word2.size(), 0));
        map[0][0] = (word1[0] == word2[0])?1:0;
        for(int i = 1; i < word1.size(); i++)
            map[i][0] = (word1[i] == word2[0])?1:map[i-1][0];
        for(int i = 1; i < word2.size(); i++)
            map[0][i] = (word1[0] == word2[i])?1:map[0][i-1];
        for(int i = 1; i < word1.size(); i++) {
            for(int j = 1; j < word2.size(); j++) {
                if(word1[i] == word2[j])
                    map[i][j] = map[i-1][j-1] + 1;
                if(map[i][j-1] > map[i][j])
                    map[i][j] = map[i][j-1];
                if(map[i-1][j] > map[i][j])
                    map[i][j] = map[i-1][j];
            }
        }
        int len = map[word1.size()-1][word2.size()-1];
        return word1.size() + word2.size() - len * 2;
    }
};