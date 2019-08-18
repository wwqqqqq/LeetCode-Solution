class Solution {
public:
    int lessthan(vector<string>& D, int num) {
        if(num <= 1)
            return 0;
        for(int i = 0; i < D.size(); i++)
            if(D[i][0] >= num + '0')
                return i;
        return D.size();
    }
    bool find(vector<string>& D, int num) {
        if(num == 0)
            return false;
        int beg = 0;
        int end = D.size() - 1;
        while(beg <= end) {
            int mid = (beg + end) / 2;
            if(D[mid][0] == num + '0')
                return true;
            else if(D[mid][0] < num + '0')
                beg = mid + 1;
            else end = mid - 1;
        }
        return false;
    }
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        vector<int> maximum;
        while(N > 0) {
            maximum.push_back(N % 10);
            N = N / 10;
        }
        int sum = 0;
        for(int i = 1; i < maximum.size(); i++) {
            int count = 1;
            for(int j = 0; j < i; j++) {
                count = count * D.size();
            }
            sum += count;
        }
        // using maximum.size() digits
        int i;
        for(i = maximum.size()-1; i >= 0; i--) {
            int k = lessthan(D, maximum[i]);
            if(k > 0) {
                int count = k;
                for(int j = 0; j < i; j++)
                    count = count * D.size();
                sum += count;
            }
            if(find(D, maximum[i]) == false)
                break;
        }
        if(i < 0)
            sum++;
        return sum;
    }
};