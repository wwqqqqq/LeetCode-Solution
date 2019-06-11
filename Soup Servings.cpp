class Solution {
public:
    double sametime(int n1, int n2, vector<vector<double>> &result, int N) {
        if(n1 <= 0 && n2 <= 0)
            return 1;
        else if(n1 <= 0 || n2 <= 0)
            return 0;
        int x = (N-n1) / 25;
        int y = (N-n2) / 25;
        if(result[x][y] >= 0)
            return result[x][y];
        double p = 0;
        // op1
        p += sametime(n1-100, n2, result, N);
        // op2
        if(n1 <= 75 && n2 <= 25)
            p += 1;
        else p += sametime(n1-75, n2-25, result, N);
        // op3
        if(n1 <= 50 && n2 <= 50)
            p += 1;
        else p += sametime(n1-50, n2-50, result, N);
        // op4
        if(n1 <= 25 && n2 <= 75)
            p += 1;
        else p += sametime(n1-25, n2-75, result, N);
        //result.insert(pair<pair<int,int>,double>(key, p));
        p = p / 4;
        result[x][y] = p;
        return p;
    }
    double afirst(int n1, int n2, vector<vector<double>> &result, int N) {
        if(n1 <= 0 && n2 > 0)
            return 1.0;
        else if(n2 <= 0)
            return 0.0;
        int x = (N-n1) / 25;
        int y = (N-n2) / 25;
        if(result[x][y] >= 0)
            return result[x][y];
        double p = 0;
        // op1
        if(n1 <= 100)
            p += 1;
        else p += afirst(n1-100, n2, result, N);
        // op2
        if(n1 <= 75 && n2 > 25)
            p += 1;
        else p += afirst(n1-75, n2-25, result, N);
        // op3
        if(n1 <= 50 && n2 > 50)
            p += 1;
        else p += afirst(n1-50, n2-50, result, N);
        // op4
        if(n1 <= 25 && n2 > 75)
            p += 1;
        else p += afirst(n1-25, n2-75, result, N);
        p = p / 4;
        //result.insert(pair<pair<int,int>,double>(key, p));
        result[x][y] = p;
        return p;
    }
    double soupServings(int N) {
        int times = N / 50;
        //if(N % 50 != 0) times++;
        vector<vector<double>> result1(N/25, vector<double>(N/25, -1.0));
        vector<vector<double>> result2(N/25, vector<double>(N/25, -1.0));
        while(times > 0) {
            int i = 4 * times - N / 25;
            if(i < 0) i = 0;
            int x = N - 100 * times + 25 * i, y = N - 25 * i;
            for(; i <= 3 * times && y > 0; i++, x += 25, y -= 25) {
                if(x <= 0)
                    continue;
                afirst(x, y, result1, N);
                sametime(x, y, result2, N);
            }
            times--;
        }
        return afirst(N, N, result1, N) + sametime(N, N, result2, N) / 2;
    }
};