// NOT optimal solution!
// will exceed memory limit if the given string is too long...
class Solution {
public:
    map<pair<int,int>,set<string>> visited;
    void add2Set(set<string>& subs, int beg, int end, string pre, string seq) {
        auto iter = visited.find(pair<int,int>(beg,end));
        if(iter != visited.end()) {
            auto subset = iter -> second;
            for(auto iter2 = subset.begin(); iter2 != subset.end(); iter2++)
                subs.insert(pre + *iter2 + seq);
        }
    }
    void findPalindromicSubsequences(string s, int beg, int end) {
        int len = end - beg + 1;
        if(beg < 0 || end >= s.size() || len <= 0) {
            return;
        }
        if(visited.find(pair<int,int>(beg, end)) != visited.end())
            return;
        set<string> subs;
        for(int i = beg; i <= end; i++) {
            subs.insert(s.substr(i, 1));
        }
        if(end == beg) {
            visited.insert(pair<pair<int,int>,set<string>>(pair<int,int>(beg,end),subs));
            return;
        }
        findPalindromicSubsequences(s, beg+1, end-1);
        string empty = "";
        add2Set(subs, beg+1, end-1, empty, empty);
        if(s[beg] == s[end]) {
            string t = s.substr(beg, 1);
            subs.insert(t+t);
            add2Set(subs, beg+1, end-1, t, t);
            visited.insert(pair<pair<int,int>,set<string>>(pair<int,int>(beg,end),subs));
            return;
        }
        for(int i = end; i > beg; i--) {
            if(s[i] == s[beg]) {
                string t = s.substr(beg, 1);
                subs.insert(t + t);
                findPalindromicSubsequences(s, beg+1, i-1);
                add2Set(subs, beg+1, i-1, t, t);
                break;
            }
        }
        for(int i = beg; i < end; i++) {
            if(s[i] == s[end]) {
                string t = s.substr(end, 1);
                subs.insert(t + t);
                findPalindromicSubsequences(s, i+1, end-1);
                add2Set(subs, i+1, end-1, t, t);
                break;
            }
        }
        visited.insert(pair<pair<int,int>,set<string>>(pair<int,int>(beg,end),subs));
    }
    /*void findPalindromicSubsequences(string s, int beg, int end) {
        int len = end - beg + 1;
        if(beg < 0 || end >= s.size() || len <= 0) {
            return;
        }
        if(visited.find(pair<int,int>(beg, end)) != visited.end())
            return;
        set<string> subs;
        for(int i = beg; i <= end; i++) {
            subs.insert(s.substr(i, 1));
        }
        for(int i = beg; i < end; i++) {
            if(s[i] == s[i+1]) {
                subs.insert(s.substr(i, 2));
            }
            string t = s.substr(i, 1);
            for(int j = i + 2; j <= end; j++) {
                if(s[i] != s[j])
                    continue;
                findPalindromicSubsequences(s, i + 1, j - 1);
                auto iter = visited.find(pair<int,int>(i + 1, j - 1));
                if(iter != visited.end()) {
                    auto subset = iter -> second;
                    for(auto iter2 = subset.begin(); iter2 != subset.end(); iter2++) {
                        subs.insert(t + *iter2 + t);
                    }
                }
            }
        }
        visited.insert(pair<pair<int,int>,set<string>>(pair<int,int>(beg,end),subs));
    }*/
    /*void findPalindromicSubsequences(string s, set<string>& subs) {
        int len = s.size();
        if(len == 0)
            return;
        if(len == 1) {
            subs.insert(s);
            return;
        }
        int len1 = len / 2;
        int len2 = len - len1;
        string s1 = s.substr(0, len1);
        string s2 = s.substr(len1);
        findPalindromicSubsequences(s1, subs);
        findPalindromicSubsequences(s2, subs);
        for(int i = 0; i < len1; i++) {
            for(int j = 0; j < len2; j++) {
                if(s1[i] != s2[j])
                    continue;
                string t(1, s1[i]);
                subs.insert(t+t);
                set<string> temp;
                findPalindromicSubsequences(s.substr(i + 1, len1 + j - i - 1), temp);
                for(auto iter = temp.begin(); iter != temp.end(); iter++) {
                    string str = t + *iter + t;
                    subs.insert(str);
                }
            }
        }
    }*/
    int countPalindromicSubsequences(string S) {
        //set<string> subs;
        findPalindromicSubsequences(S, 0, S.size() - 1);
        auto iter = visited.find(pair<int,int>(0, S.size() - 1));
        if(iter == visited.end())
            return 0;
        return (iter -> second).size();
    }
};