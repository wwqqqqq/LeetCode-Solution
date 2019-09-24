class Solution {
public:
    vector<string> split(string s) {
        vector<string> result;
        int beg = 0, end = -1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                if(end >= beg) {
                    result.push_back(s.substr(beg, end-beg+1));
                    end = beg - 1;
                }
                continue;
            }
            else {
                if(i == 0 || (i >= 1 && s[i-1] == ' ')) {
                    beg = i;
                }
                end = i;
            }
        }
        if(end >= beg)
            result.push_back(s.substr(beg, end-beg+1));
        return result;
    }
    string reverseWords(string s) {
        vector<string> words = split(s);
        string result;
        for(int i = words.size() - 1; i >= 0; i--) {
            result.append(words[i]);
            if(i > 0) {
                result.append(1, ' ');
            }
        }
        return result;
    }
};