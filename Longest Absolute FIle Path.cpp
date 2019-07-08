class Solution {
public:
    int lengthLongestPath(string input) {
        stack<string> st;
        int max = 0;
        //int max_depth = 0;
        int len = 0;
        for(int i = 0; i < input.size();) {
            if(input[i] == '\n')
                continue;
            int j = i;
            int depth = 1;
            bool isfile = false;
            for(; j < input.size(); j++) {
                if(input[j] == '\t') {
                    depth++;
                    i++;
                }
                else if(input[j] == '.')
                    isfile = true;
                else if(input[j] == '\n')
                    break;
            }
            string s = input.substr(i, j-i);
            while(st.size() >= depth) {
                len -= (st.top()).size();
                st.pop();
            }
            st.push(s);
            len += s.size();
            if(isfile && max < len + depth - 1)
                max = len + depth - 1;
            /*if(depth > max_depth)
                max_depth = depth;*/
            i = j + 1;
        }
        return max;
    }
};