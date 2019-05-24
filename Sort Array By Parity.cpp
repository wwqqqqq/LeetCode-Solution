class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int current = -1;
        for(int i = 0; i < A.size(); i++) {
            if(current == -1) {
                if(A[i] % 2 == 0) {
                    // even
                    continue;
                }
                else {
                    // odd
                    current = i;
                }
            }
            else {
                if(A[i] % 2 == 0) {
                    // even
                    int temp = A[i];
                    A[i] = A[current];
                    A[current] = temp;
                    current++;
                }
                else {
                    // odd
                    continue;
                }
            }
        }
        return A;
    }
};