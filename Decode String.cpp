class Solution {
public:
    string decodeString(string s) {
        string result;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                int start = i;
                while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    i++;
                }
                int k = stoi(s.substr(start, i - start));
                if(i < s.size() && s[i] == '[') {
                    int parenCount = 1;
                    start = i;
                    for(i++; i < s.size(); i++) {
                        if(s[i] == '[') parenCount++;
                        else if(s[i] == ']') parenCount--;
                        if(s[i] == ']' && parenCount == 0)
                            break;
                    }
                    string subs = decodeString(s.substr(start + 1, i - start - 1));
                    for(int j = 0; j < k; j++) {
                        result += subs;
                    }
                }
            }
            else {
                result += s[i];
            }
        }
        return result;
    }
};