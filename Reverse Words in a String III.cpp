class Solution {
public:
    string reverseWords(string s) {
        for(int i = 0; i < s.size();) {
            if(s[i] == ' ') {
                i++;
                continue;
            }
            int st = i;
            int ed = st;
            for(; ed < s.size(); ed++) {
                if(s[ed] == ' ')
                    break;
            }
            reverse(s.begin()+st,s.begin()+ed);
            i = ed + 1;
        }
        return s;
    }
};