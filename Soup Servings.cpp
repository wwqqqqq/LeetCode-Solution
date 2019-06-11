class Solution {
public:
    double sametime(int n1, int n2) {
        if(n1 <= 0 && n2 <= 0)
            return 1;
        else if(n1 <= 0 || n2 <= 0)
            return 0;
        double p = 0;
        // op1
        p += sametime(n1-100, n2);
        // op2
        if(n1 <= 75 && n2 <= 25)
            p += 1;
        else p += sametime(n1-75, n2-25);
        // op3
        if(n1 <= 50 && n2 <= 50)
            p += 1;
        else p += sametime(n1-50, n2-50);
        // op4
        if(n1 <= 25 && n2 <= 75)
            p += 1;
        else p += sametime(n1-25, n2-75);
        p = p / 4;
        return p;
    }
    double afirst(int n1, int n2) {
        if(n1 <= 0 && n2 > 0)
            return 1.0;
        else if(n2 <= 0)
            return 0.0;
        double p = 0;
        // op1
        if(n1 <= 100)
            p += 1;
        else p += afirst(n1-100, n2);
        // op2
        if(n1 <= 75 && n2 > 25)
            p += 1;
        else p += afirst(n1-75, n2-25);
        // op3
        if(n1 <= 50 && n2 > 50)
            p += 1;
        else p += afirst(n1-50, n2-50);
        // op4
        if(n1 <= 25 && n2 > 75)
            p += 1;
        else p += afirst(n1-25, n2-75);
        p = p / 4;
        return p;
    }
    void recursive_sametime(vector<double> &result, int N) {
        int t = (result.size() - 4) / 3;
        if(result.size() < 4)
            return;
        int x = N - 100 * t;
        int y = N;
        for(int i = 0; i + 3 < result.size(); i++, x += 25, y -= 25) {
            if(x <= 0 && y <= 0)
                result[i] = 1;
            else if(x <= 0 || y <= 0)
                result[i] = 0;
            else {
                double sum = result[i] + result[i+1] + result[i+2] + result[i+3];
                result[i] = sum / 4;
            }
        }
        result.erase(result.begin() + result.size() - 3, result.end());
    }
    void recursive_afirst(vector<double> &result, int N) {
        int t = (result.size() - 4) / 3;
        if(result.size() < 4)
            return;
        int x = N - 100 * t;
        int y = N;
        for(int i = 0; i + 3 < result.size(); i++, x += 25, y -= 25) {
            if(x <= 0 && y > 0)
                result[i] = 1;
            else if(y <= 0)
                result[i] = 0;
            else {
                double sum = result[i] + result[i+1] + result[i+2] + result[i+3];
                result[i] = sum / 4;
            }
        }
        result.erase(result.begin() + result.size() - 3, result.end());
    }
    double soupServings(int N) {
        int times = N / 50;
        //if(N % 50 != 0) times++;
        vector<double> result1(3*times + 1, 0);
        vector<double> result2(3*times + 1, 0);
        int x = N - 100 * times;
        int y = N;
        for(int i = 0; i <= 3 * times; i++, x += 25, y -= 25) {
            result1[i] = afirst(x, y);
            result2[i] = sametime(x, y);
        }
        while(result1.size() > 1) {
            recursive_afirst(result1, N);
        }
        while(result2.size() > 1) {
            recursive_sametime(result2, N);
        }
        return result1[0] + result2[0] / 2;
    }
};