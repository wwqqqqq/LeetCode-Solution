class Solution {
public:
    int MIN(int a, int b) {
        if(a < b)
            return a;
        return b;
    }
    int MAX(int a, int b) {
        if(a < b)
            return b;
        return a;
    }
    int sumSubarrayMins(vector<int>& A, int beg, int end) {
        if(A.size() == 0 || beg >= end)
            return 0;
        if(end - beg == 1)
            return A[beg];
        if(end - beg == 2) {
            if(A[beg] > A[beg+1])
                return 2 * A[beg+1] + A[beg];
            return 2 * A[beg] + A[beg+1];
        }
        int min_index = beg;
        int min = A[beg];
        for(int i = beg+1; i < end; i++)
            if(A[i] < min) {
                min = A[i];
                min_index = i;
            }
        int sum = sumSubarrayMins(A, beg, min_index) + sumSubarrayMins(A, min_index+1, end);
        // end - beg: 1
        // end - beg - 1: 2
        // ...
        // max + 1: end - beg - max
        // max(min_index - beg + 1, end - min_index): min(min_index)
        // ...
        // min(min_index - beg + 1, end - min_index): length
        // ...
        // 1: 1
        int bound = MIN(min_index - beg + 1, end - min_index);
        int bound2 = MAX(min_index - beg + 1, end - min_index);
        int count = ((1 + bound) * bound) / 2 + ((end - beg - bound2 + 1) * (end - beg - bound2)) / 2 + bound * (bound2 - bound);
        sum = sum % 1000000007;
        sum += count * min;
        return sum % 1000000007;
    }
    int sumSubarrayMins(vector<int>& A) {
        return sumSubarrayMins(A, 0, A.size());
    }
    /*int min(int a, int b) {
        if(a < b)
            return a;
        return b;
    }
    int sumSubarrayMins(vector<int>& A) {
        int sum = 0;
        for(int i = 0; i < A.size(); i++) {
            int last = A[i];
            sum += A[i];
            for(int j = i + 1; j < A.size(); j++) {
                int result = min(A[j], last);
                sum += result;
                last = result;
                sum = sum % (1000000007);
            }
        }
        return sum;
    }*/
};