class Solution {
public:
    map<pair<int,int>, double> result;
    double largestSum(vector<int> A, int K, int beg) {
        auto iter_map = result.find(pair<int, int>(K, beg));
        if(iter_map != result.end())
            return iter_map -> second;
        if(beg >= A.size() || beg < 0 || K == 0)
            return 0;
        if(K == 1) {
            double sum = 0;
            int size = A.size() - beg;
            for(; beg < A.size(); beg++)
                sum += A[beg];
            return sum / size;
        }
        int max_size = A.size() - beg - K + 1;
        if(max_size == 1) {
            double sum = 0;
            for(; beg < A.size(); beg++)
                sum += A[beg];
            return sum;
        }
        else if(max_size < 1)
            return 0;
        double sum = 0;
        double res = 0;
        int i = beg;
        int size = 1;
        while(size <= max_size && i < A.size()) {
            sum += A[i];
            double temp = sum / size + largestSum(A, K - 1, i + 1);
            if(temp > res)
                res = temp;
            size++;
            i++;
        }
        result.insert(pair<pair<int,int>,double>(pair<int,int>(K, beg), res));
        return res;
    }
    double largestSumOfAverages(vector<int>& A, int K) {
        // 暴力枚举
        return largestSum(A, K, 0);
    }
};