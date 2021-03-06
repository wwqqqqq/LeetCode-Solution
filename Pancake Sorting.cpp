/*
969. Pancake Sorting
Given an array A, we can perform a pancake flip: We choose some positive integer k <= A.length, then reverse the order of the first k elements of A.  We want to perform zero or more pancake flips (doing them one after another in succession) to sort the array A.

Return the k-values corresponding to a sequence of pancake flips that sort A.  Any valid answer that sorts the array within 10 * A.length flips will be judged as correct.

 

Example 1:

Input: [3,2,4,1]
Output: [4,2,4,3]
Explanation: 
We perform 4 pancake flips, with k values 4, 2, 4, and 3.
Starting state: A = [3, 2, 4, 1]
After 1st flip (k=4): A = [1, 4, 2, 3]
After 2nd flip (k=2): A = [4, 1, 2, 3]
After 3rd flip (k=4): A = [3, 2, 1, 4]
After 4th flip (k=3): A = [1, 2, 3, 4], which is sorted. 

Example 2:

Input: [1,2,3]
Output: []
Explanation: The input is already sorted, so there is no need to flip anything.
Note that other answers, such as [3, 3], would also be accepted.
 

Note:

1 <= A.length <= 100
A[i] is a permutation of [1, 2, ..., A.length]
*/

class Solution {
public:
    void reverse(vector<int>& A, int k) {
        if(k == 0 || k > A.size() || k == 1)
            return;
        for(int i = 0; 2 * i < k - 1; i++) {
            int t = A[i];
            A[i] = A[k-i-1];
            A[k-i-1] = t;
        }
    }
    int ifSorted(vector<int>& A) {
        for(int i = 0; i < A.size() - 1; i++) {
            if(A[i+1] < A[i])
                return -1;
        }
        return 1;
    }
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        //int r = pancakeSort(A, -1, 0, res);
        for(int size = A.size(); size > 0; size--) {
            int max = A[0];
            int ind = 0;
            for(int i = 0; i < size; i++)
                if(max < A[i]) {
                    ind = i;
                    max = A[i];
                }
            if(ind == size - 1)
                continue;
            if(ind != 0) {
                res.push_back(ind + 1);
                reverse(A, ind+1);
            }
            res.push_back(size);
            reverse(A, size);
        }
        
        return res;
    }
};