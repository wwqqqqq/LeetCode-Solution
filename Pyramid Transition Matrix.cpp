class Solution {
public:
    map<string,string> allowed_map;
    string find_allowed(string key) {
        auto iter = allowed_map.find(key);
        if(iter == allowed_map.end())
            return "";
        return iter->second;
    }
    string find_allowed(char c1, char c2) {
        string key;
        key.append(1,c1);
        key.append(1,c2);
        auto iter = allowed_map.find(key);
        if(iter == allowed_map.end())
            return "";
        return iter->second;
    }
    bool pyramid(string bottom) {
        if(bottom.size() == 1 || bottom.size() == 0)
            return true;
        if(bottom.size() == 2) {
            string temp = find_allowed(bottom);
            if(temp.size() == 0)
                return false;
            return true;
        }
        vector<string> upper;
        for(int i = 0; i < bottom.size()-1; i++) {
            string key = bottom.substr(i, 2);
            string allowed = find_allowed(key);
            if(allowed.size() == 0)
                return false;
            if(upper.size() == 0) {
                for(int j = 0; j < allowed.size(); j++) {
                    string s;
                    s.append(1, allowed[j]);
                    upper.push_back(s);
                }
            }
            else {
                int len = upper.size();
                vector<string> new_upper;
                for(int j = 0; j < len; j++) {
                    string s = upper[j];
                    char last = s[s.size()-1];
                    for(int k = 0; k < allowed.size(); k++) {
                        string temp = find_allowed(last, allowed[k]);
                        if(temp.size() == 0)
                            continue;
                        string t = s;
                        t.append(1, allowed[k]);
                        new_upper.push_back(t);
                    }
                    if(new_upper.size() == 0)
                        return false;
                    upper = new_upper;
                }
            }
        }
        for(int i = 0; i < upper.size(); i++)
            if(pyramid(upper[i]))
                return true;
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        if(bottom.size() == 1 || bottom.size() == 0)
            return true;
        for(int i = 0; i < allowed.size(); i++) {
            string key = allowed[i].substr(0,2);
            auto iter = allowed_map.find(key);
            if(iter == allowed_map.end()) {
                string s;
                s.append(1, allowed[i][2]);
                allowed_map.insert(pair<string,string>(key,s));
            }
            else {
                (iter->second).append(1, allowed[i][2]);
            }
        }
        return pyramid(bottom);
    }
};