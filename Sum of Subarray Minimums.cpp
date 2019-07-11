class Solution {
public:
    /* TACT 1 O(n) */
    int sumSubarrayMins(vector<int>& A) {
        vector<int> result(A.size(), 0);
        vector<int> ofst(A.size(), 0);
        // ofst[i] = j - i, where j is the minimum index greater than i while A[j] < A[i]
        ofst[A.size() - 1] = 0;
        for(int i = A.size() - 2; i >= 0; i--) {
            if(A[i] > A[i+1]) {
                ofst[i] = 1;
                continue;
            }
            int r = i + 1;
            while(r < A.size() && A[r] >= A[i]) {
                if(ofst[r] == 0) {
                    ofst[i] = 0;
                    break;
                }
                r = r + ofst[r];
            }
            if(r < A.size() && A[r] < A[i])
                ofst[i] = r - i;
        }
        // result[i] is the sum of mins of all subarrays that begin with A[i]
        result[A.size() - 1] = A[A.size() - 1];
        for(int i = A.size() - 2; i >= 0; i--) {
            if(ofst[i] == 0) {
                result[i] = (A.size() - i) * A[i];
                continue;
            }
            result[i] = A[i] * ofst[i] + result[i + ofst[i]];
            result[i] = result[i] % 1000000007;
        }
        int sum = 0;
        for(int i = 0; i < result.size(); i++) {
            sum += result[i];
            sum = sum % 1000000007;
        }
        return sum;
    }
    /* TACT 2 O(nlogn) ~ O(n^2)
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
    }*/
    /* TACT 3 O(n^2)
    int min(int a, int b) {
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