class Solution {
public:
    int longestValidParentheses(string s) {
        int max = 0;
        for(int i = 0; i < s.size();) {
            if(s[i] == ')') {
                i++;
                continue;
            }
            int j;
            int count = 0;
            int len = 0;
            int first = -1;
            for(j = i; j < s.size(); j++) {
                if(s[j] == '(') {
                    count++;
                    if(count == 2 && first == -1)
                        first = j;
                }
                if(s[j] == ')') {
                    count--;
                    if(count == 0)
                        len = j - i + 1;
                    else if(count < 0)
                        break;
                }
            }
            if(len > max) max = len;
            if(count == 0)
                break;
            else if(count < 0)
                i = j + 1;
            else i = first;
        }
        return max;
        /* calculate the longest subsequence of s that consists valid parentheses
        int count = 0;
        int result = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                count++;
            else if(s[i] == ')') {
                count--;
                if(count < 0) {
                    result++;
                    count++;
                }
            }
        }
        result += count;
        return s.size() - result;
        */
    }
};