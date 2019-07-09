class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unsigned short x = 0;
        for(int i = 0; i < 8; i++) {
            x *= 2;
            x += cells[i];
        }
        vector<unsigned short> m(256, 0);
        vector<int> visited(256, -1);
        /*for(int i = 0; i < N; i++) {
            unsigned short x1 = x >> 1;
            unsigned short x2 = x << 1;
            x = (~(x1 ^ x2)) & 0x7E;
        }*/
        for(int i = 0; i < 256; i++) {
            unsigned short n = i;
            unsigned short n1 = n >> 1;
            unsigned short n2 = n << 1;
            n = (~(n1 ^ n2)) & 0x7E;
            m[i] = n;
        }
        int i;
        for(i = 0; i < N; i++) {
            x = m[x];
            if(visited[x] == -1)
                visited[x] = i;
            else {
                // loop from visited[x] to i-1
                int loop_len = i - visited[x];
                int left_size = N - i;
                int left_loop = (left_size - 1) / loop_len;
                i += loop_len * left_loop;
            }
        }
        for(i++; i < N; i++) {
            x = m[x];
        }
        for(int i = 7; i >= 0; i--) {
            cells[i] = x % 2;
            x = x / 2;
        }
        return cells;
        /*for(int i = 0; i < N; i++) {
            int last = cells[0];
            for(int i = 1; i < cells.size()-1; i++) {
                int temp = cells[i];
                if(last == cells[i+1])
                    cells[i] = 1;
                else cells[i] = 0;
                last = temp;
            }
            cells[0] = 0;
            cells[cells.size()-1] = 0;
        }
        return cells;*/
    }
};