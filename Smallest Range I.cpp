class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        if(A.size() == 0)
            return 0;
        int min = A[0];
        int max = A[0];
        for(int i = 0; i < A.size(); i++) {
            if(A[i] < min) min = A[i];
            if(A[i] > max) max = A[i];
        }
        return (max - min - 2 * K > 0)? (max - min - 2 * K):0;
    }
};