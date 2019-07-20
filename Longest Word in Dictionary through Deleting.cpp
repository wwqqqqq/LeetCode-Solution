bool compare(const string &s1, const string &s2)
    {
        if(s1.size() > s2.size())
            return true;
        else if(s1.size() < s2.size())
            return false;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] < s2[i])
                return true;
            else if(s1[i] > s2[i])
                return false;
        }
        return true;
    }

class Solution {
public:
    bool canbeformed(string s, string t) {
        int current = 0;
        for(int i = 0; i < t.size(); i++) {
            int j;
            for(j = current; j < s.size(); j++) {
                if(t[i] == s[j]) {
                    current = j + 1;
                    break;
                }
            }
            if(j >= s.size())
                return false;
        }
        return true;
    }

    string findLongestWord(string s, vector<string>& d) {
        // sort
        sort(d.begin(), d.end(), compare);
        for(int i = 0; i < d.size(); i++)
            if(canbeformed(s, d[i]))
                return d[i];
        return "";
    }
};