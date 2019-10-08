class Solution {
public:
    void square(vector<int>& A) {
        for(int i = 0; i < A.size(); i++) {
            A[i] = A[i] * A[i];
        }
    }
    vector<int> merge(vector<int>& v1, vector<int>& v2) {
        vector<int> result;
        auto iter1 = v1.begin();
        auto iter2 = v2.begin();
        while(iter1 != v1.end() && iter2 != v2.end()) {
            if(*iter1 < *iter2) {
                result.push_back(*iter1);
                iter1++;
            }
            else {
                result.push_back(*iter2);
                iter2++;
            }
        }
        if(iter1 != v1.end())
            result.insert(result.end(), iter1, v1.end());
        if(iter2 != v2.end())
            result.insert(result.end(), iter2, v2.end());
        return result;
    }
    vector<int> sortedSquares(vector<int>& A) {
        if(A.size() == 0)
            return A;
        if(A[0] >= 0) {
            square(A);
            return A;
        }
        else if(A[A.size()-1] <= 0) {
            square(A);
            reverse(A.begin(), A.end());
            return A;
        }
        int mid = 0;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] >= 0) {
                mid = i;
                break;
            }
        }
        vector<int> firstHalf(A.begin(), A.begin() + mid);
        vector<int> secondHalf(A.begin() + mid, A.end());
        square(firstHalf);
        square(secondHalf);
        reverse(firstHalf.begin(), firstHalf.end());
        return merge(firstHalf, secondHalf);
    }
};