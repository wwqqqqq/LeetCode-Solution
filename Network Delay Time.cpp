class Solution {
public:
    void modify(vector<vector<int>>& distance, int x, int y, int r) {
        if((distance[x][y]<r&&distance[x][y]!=-1) || x==y)
            return;
        distance[x][y] = r;
        int N = distance.size();
        for(int j=0;j<N;j++) {
            if(j==x)
                continue;
            if(distance[j][x]!=-1) {
                int newr = distance[j][x] + r;
                modify(distance, j, y, newr);
            }
        }
        for(int j=0;j<N;j++) {
            if(j==y)
                continue;
            if(distance[y][j]!=-1) {
                int newr = r + distance[y][j];
                modify(distance, x, j, newr);
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> distance(N,-1);
        distance[K-1] = 0;
        set<int> nodes;
        for(int i=1;i<=N;i++)
            nodes.insert(i);
        while(nodes.size()>0) {
            int ind = 0;
            int m = -1;
            for(auto iter = nodes.begin(); iter != nodes.end(); iter++) {
                int t = distance[*iter - 1];
                if(t==-1)
                    continue;
                if(m==-1 || m>t) {
                    m = t;
                    ind = *iter;
                }
            }
            if(ind==0 || m==-1)
                return -1;
            for(int i=0;i<times.size();i++) {
                if(times[i][0]==ind) {
                    int y = times[i][1];
                    if(nodes.find(y)==nodes.end())
                        continue;
                    if(distance[y-1]==-1 || distance[y-1]>times[i][2]+m)
                        distance[y-1] = times[i][2] + m;
                }
            }
            nodes.erase(ind);
        }
        int m = -1;
        for(int i=0;i<N;i++) {
            if(distance[i]>m)
                m = distance[i];
        }
        return m;
        /*vector<vector<int>> distance(N);
        for(int i=0;i<N;i++) {
            //vector<int> temp;
            for(int j=0;j<N;j++)
                distance[i].push_back(-1);
            distance[i][i] = 0;
            //distance.push_back(temp);
        }
        for(int i=0;i<times.size();i++) {
            int x = times[i][0] - 1;
            int y = times[i][1] - 1;
            int r = times[i][2];
            modify(distance, x, y, r);
        }
        int m = -1;
        K = K - 1;
        for(int i=0;i<N;i++) {
            if(K==i)
                continue;
            if(distance[K][i] == -1)
                return -1;
            else if(distance[K][i]>m)
                m = distance[K][i];
        }
        return m;*/
    }
};