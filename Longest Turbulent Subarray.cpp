class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int max = 0;
        if(A.size() < 2)
            return A.size();
        for(int i = 0; i < A.size() - 1;) {
            // > = -1
            // < =  1
            while(i < A.size() - 1 && A[i] == A[i+1])
                i++;
            if(A.size() - i <= max)
                break;
            int last = 0;
            int j;
            for(j = i; j < A.size() - 1; j++) {
                if(A[j] < A[j+1] && last == 1 || A[j] > A[j+1] && last == -1 || A[j] == A[j+1]) {
                    if(max < j - i + 1)
                        max = j - i + 1;
                    i = j;
                    break;
                }
                last = (A[j] < A[j+1])? 1: -1;
            }
            if(j >= A.size() - 1) {
                if(max < j - i + 1)
                    max = j - i + 1;
                break;
            }
        }
        return max;
    }
};