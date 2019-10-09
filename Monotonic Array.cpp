class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if(A.size() < 2)
            return true;
        bool increase = true;
        int i = 0;
        for(; i + 1 < A.size(); i++) {
            if(A[i] == A[i+1])
                continue;
            increase = (A[i] < A[i+1])?true: false;
            break;
        }
        for(; i + 1 < A.size(); i++) {
            //if(A[i] == A[i+1])
            //    return false;
            if(increase && A[i] > A[i+1])
                return false;
            if(!increase && A[i] < A[i+1])
                return false;
        }
        return true;
    }
};