class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size(), 0);
        result[T.size() - 1] = 0;
        for(int i = T.size() - 2; i >= 0; i--) {
            if(T[i] < T[i+1]) {
                result[i] = 1;
                continue;
            }
            int r = i + 1;
            while(r < T.size() && T[r] <= T[i]) {
                if(result[r] == 0) {
                    result[i] = 0;
                    break;
                }
                r = r + result[r];
            }
            if(r < T.size() && T[r] > T[i])
                result[i] = r - i;
        }
        return result;
    }
};