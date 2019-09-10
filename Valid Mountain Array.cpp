class Solution {
public
    bool validMountainArray(vectorint& A) {
        if(A.size()  3  A[0] = A[1])
            return false;
        bool first_half = true;
        for(int i = 0; i  A.size() - 1; i++) {
            if(first_half) {
                if(A[i]  A[i+1])
                    continue;
                else if(A[i] == A[i+1])
                    return false;
                else first_half = false;
            }
            else {
                if(A[i]  A[i+1])
                    continue;
                else return false;
            }
        }
        if(first_half)
            return false;
        return true;
    }
};