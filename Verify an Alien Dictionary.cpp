class Solution {
public:
    bool lessEqual(string w1, string w2, vector<int>& order) {
        for(int i = 0; i < w1.size() && i < w2.size(); i++) {
            if(order[w1[i]-'a'] < order[w2[i]-'a'])
                return true;
            else if(order[w1[i]-'a'] == order[w2[i]-'a'])
                continue;
            else return false;
        }
        if(w1.size() <= w2.size())
            return true;
        return false;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        // increasing order, decreasing order, or not specified?
        vector<int> index(26,0);
        for(int i = 0; i < order.size(); i++) {
            index[order[i]-'a'] = i;
        }
        for(int i = 0; i + 1 < words.size(); i++) {
            if(!lessEqual(words[i], words[i+1], index))
                return false;
        }
        return true;
    }
};