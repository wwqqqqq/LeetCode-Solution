class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> group(26, -1);
        int current = 0;
        // find all '=='
        for(int i = 0; i < equations.size(); i++) {
            if(equations[i][1] == '!')
                continue;
            int e1 = equations[i][0] - 'a';
            int e2 = equations[i][3] - 'a';
            if(e1 == e2)
                continue;
            if(group[e1] == -1 || group[e2] == -1) {
                if(group[e1] != -1)
                    group[e2] = group[e1];
                else if(group[e2] != -1)
                    group[e1] = group[e2];
                else {
                    group[e1] = current;
                    group[e2] = current;
                    current++;
                }
            }
            else if(group[e1] != group[e2]) {
                int t = group[e2];
                for(int j = 0; j < 26; j++) {
                    if(group[j] == t)
                        group[j] = group[e1];
                }
            }
        }
        // find all '!='
        for(int i = 0; i < equations.size(); i++) {
            if(equations[i][1] == '=')
                continue;
            int e1 = equations[i][0] - 'a';
            int e2 = equations[i][3] - 'a';
            if(e1 == e2)
                return false;
            if(group[e1] == -1 || group[e2] == -1) 
                continue;
            else if(group[e1] == group[e2])
                return false;
        }
        return true;
    }
};