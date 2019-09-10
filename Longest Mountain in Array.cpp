class Solution {
public:
    int getMountainSize(vector<int>& A, int index) {
        int count = 1;
        for(int i = index - 1; i >= 0; i--) {
            if(A[i] < A[i+1])
                count++;
            else break;
        }
        for(int i = index + 1; i < A.size(); i++) {
            if(A[i] < A[i-1])
                count++;
            else break;
        }
        return count;
    }
    int longestMountain(vector<int>& A) {
        if(A.size() < 3)
            return 0;
        int max = 0;
        for(int i = 1; i < A.size() - 1; i++) {
            if(A[i] > A[i-1] && A[i] > A[i+1]) {
                int t = getMountainSize(A, i);
                if(t > max)
                    max = t;
            }
        }
        return max;
    }
};