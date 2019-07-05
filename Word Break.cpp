class Solution {
public:
    map<string, bool> m;
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size() == 0)
            return true;
        auto iter = m.find(s);
        if(iter != m.end())
            return iter->second;
        vector<string> dict(wordDict);
        for(int i = 0; i < s.size(); i++) {
            if(dict.size() == 0)
                break;
            for(int j = 0; j < dict.size(); j++) {
                if(dict[j].size() <= i || dict[j][i] != s[i]) {
                    dict.erase(dict.begin() + j);
                    j--;
                    continue;
                }
                if(i == dict[j].size() - 1) {
                    // fit!!!
                    if(wordBreak(s.substr(i+1), wordDict)) {
                        m.insert(pair<string,bool>(s,true));
                        return true;
                    }
                    dict.erase(dict.begin() + j);
                    j--;
                    continue;
                }
            }
        }
        m.insert(pair<string,bool>(s,false));
        return false;
    }
};