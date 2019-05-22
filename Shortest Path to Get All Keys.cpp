// EXCEEDS TIME LIMIT!

class Solution {
public:
    typedef struct{
        int last_direction;
        int pos_x;
        int pos_y;
        set<char> keys;
    }path;
    vector<path> visited;
    int isSame(set<char> s1, set<char> s2) {
        map<set<char>, int> mTemp;
        mTemp[s1] = 1;

        if (mTemp.find(s2) != mTemp.end())
            return 1;
        return 0;
    }
    int move(vector<string>& grid, vector<path> &s, path p, int key_num) {
        set<char> k(p.keys);
        int x = p.pos_x;
        int y = p.pos_y;
        int direction = p.last_direction;
        if(grid[x][y] >= 'a' && grid[x][y] <= 'z') {
            k.insert(grid[x][y] - 'a' + 'A');
            if(k.size() == key_num)
                return 1;
            direction = -1;
        }
        for(int i = 0; i < 4; i++) {
            if(i == 3 - direction)
                continue;
            int nx = x;
            int ny = y;
            if(i == 0) nx = x - 1; //up
            else if(i == 3) nx = x + 1; //down
            else if(i == 1) ny = y - 1; //left
            else ny = y + 1; //right
            if(nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size())
                continue;
            if(grid[nx][ny] == '#')
                continue;
            if(grid[nx][ny] >= 'A' && grid[nx][ny] <= 'Z') {
                if(k.find(grid[nx][ny]) == k.end())
                    continue;
            }
            int ok = 1;
            for(auto iter = visited.begin(); iter != visited.end(); iter++) {
                if(iter -> pos_x == nx && iter -> pos_y == ny && isSame(iter->keys, k)) {
                    ok = 0;
                    break;
                }
            }
            if(ok == 0)
                continue;
            path np;
            np.last_direction = i;
            np.pos_x = nx;
            np.pos_y = ny;
            for(auto iter=k.begin(); iter != k.end(); iter++)
                np.keys.insert(*iter);
            visited.push_back(np);
            s.push_back(np);
        }
        return 0;
    }
    int BFT(vector<string>& grid, vector<path> &s, int key_num, int depth) {
        if(s.size() == 0)
            return -1;
        vector<path> ns;
        for(int i = 0; i < s.size(); i++) {
            int ok = move(grid, ns, s[i], key_num);
            if(ok == 1)
                return depth;
        }
        s.erase(s.begin(), s.end());
        //if(ns.size() == 0)
        //    return -1;
        return BFT(grid, ns, key_num, depth+1);
    }
    int shortestPathAllKeys(vector<string>& grid) {
        // calculate init_point and key_num
        int key_num = 0;
        int x, y;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '@') {
                    x = i; y = j;
                }
                else if(grid[i][j] >= 'a' && grid[i][j] <= 'z')
                    key_num++;
            }
        }
        if(key_num == 0)
            return 0;
        vector<path> s;
        path init_point;
        init_point.last_direction = -1;
        init_point.pos_x = x;
        init_point.pos_y = y;
        s.push_back(init_point);
        return BFT(grid, s, key_num, 0);
    }
};