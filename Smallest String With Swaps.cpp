class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<set<int>> map(s.size());
        for(int i = 0; i < pairs.size(); i++) {
            int v1 = pairs[i][0];
            int v2 = pairs[i][1];
            map[v1].insert(v2);
            map[v2].insert(v1);
        }
        set<int> VISITED;
        for(int i = 0; i < s.size(); i++) {
            if(VISITED.find(i) != VISITED.end())
                continue;
            set<int> visited;
            queue<int> q;
            q.push(i);
            while(q.size() > 0) {
                int n = q.front();
                q.pop();
                visited.insert(n);
                VISITED.insert(n);
                for(auto iter = map[n].begin(); iter != map[n].end(); iter++) {
                    int node = *iter;
                    map[node].erase(n);
                    q.push(node);
                }
                map[n].erase(map[n].begin(), map[n].end());
            }
                auto iter1 = visited.end();
                iter1--;
                for(; iter1 != visited.begin(); iter1--) {
                    int end = *iter1;
                    for(auto iter2 = visited.begin(); iter2 != iter1; iter2++) {
                        auto iter3 = iter2;
                        iter3++;
                        int n1 = *iter2;
                        int n2 = *iter3;
                        if(s[n1] > s[n2]) {
                            char temp = s[n1];
                            s[n1] = s[n2];
                            s[n2] = temp;
                        }
                    }
                }
        }
        return s;
        /* TIME LIMIT EXCEEDS!!
        vector<int> groupid(s.size(), -1);
        vector<vector<int>> group;
        set<int> group_num;
        int current = 0;
        for(int i = 0; i < pairs.size(); i++) {
            int v1 = pairs[i][0];
            int v2 = pairs[i][1];
            if(groupid[v1] < 0 && groupid[v2] < 0) {
                groupid[v1] = current;
                groupid[v2] = current;
                vector<int> temp = {v1, v2};
                group.push_back(temp);
                group_num.insert(current);
                current++;
            }
            else if(groupid[v1] < 0) {
                groupid[v1] = groupid[v2];
                group[groupid[v2]].push_back(v1);
            }
            else if(groupid[v2] < 0) {
                groupid[v2] = groupid[v1];
                group[groupid[v1]].push_back(v2);
            }
            else if(groupid[v1] != groupid[v2]) {
                int t = (groupid[v1] < groupid[v2])?groupid[v2]:groupid[v1];
                int t2 = (groupid[v1] < groupid[v2])?groupid[v1]:groupid[v2];
                for(int j = 0; j < group[t].size(); j++) {
                    int n = group[t][j];
                    groupid[n] = t2;
                }
                group[t2].insert(group[t2].end(), group[t].begin(), group[t].end());
                group[t].erase(group[t].begin(), group[t].end());
                group_num.erase(t);
            }
        }
        for(auto iter = group_num.begin(); iter != group_num.end(); iter++) {
            int gid = *iter;
            sort(group[gid].begin(), group[gid].end());
            for(int i = group[gid].size() - 1; i >= 0; i--) {
                int end = group[gid][i];
                for(int j = 0; j < i; j++) {
                    int n1 = group[gid][j];
                    int n2 = group[gid][j+1];
                    if(s[n1] > s[n2]) {
                        char temp = s[n1];
                        s[n1] = s[n2];
                        s[n2] = temp;
                    }
                }
            }
        }
        return s;*/
        /* WRONG ANSWER
        while(true) {
            int count = 0;
            for(int i = 0; i < pairs.size(); i++) {
                int v1 = pairs[i][0];
                int v2 = pairs[i][1];
                if(v1 > v2) {
                    int temp = v1;
                    v1 = v2;
                    v2 = temp;
                    pairs[i][0] = v1;
                    pairs[i][1] = v2;
                }
                if(s[v1] > s[v2]) {
                    char temp = s[v1];
                    s[v1] = s[v2];
                    s[v2] = temp;
                    count++;
                }
            }
            if(count == 0)
                break;
        }
        return s;*/
    }
};