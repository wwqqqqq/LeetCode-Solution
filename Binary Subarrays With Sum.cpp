class Solution {
public:
    int zeroSubarrays(vector<int>& A) {
        int begin = 0;
        int end = 0;
        int result = 0;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] == 1)
                continue;
            begin = i;
            for(int j = i; j < A.size(); j++) {
                if(A[j] == 1) {
                    end = j - 1;
                    break;
                }
                else end = j;
            }
            int len = end - begin + 1;
            result += (len + 1) * len / 2;
            i = end;
        }
        return result;
    }
    int numSubarraysWithSum(vector<int>& A, int S) {
        if(S == 0) {
            return zeroSubarrays(A);
        }
        int prefix_zero = 0;
        int surfix_zero = 0;
        int begin = 0;
        int end = 0;
        int result = 0;
        int count = 0;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] == 1) {
                if(count == 0) {
                    prefix_zero = i;
                    begin = i;
                }
                count++;
                if(count == S) {
                    end = i;
                    break;
                }
            }
        }
        if(count < S)
            return 0;
        for(int j = end + 1; j < A.size(); j++) {
            if(A[j] == 0)
                surfix_zero++;
            else break;
        }
        result = (surfix_zero + 1) * (prefix_zero + 1);
        prefix_zero = 0;
        for(int i = begin + 1; i < A.size(); ) {
            if(A[i] == 0) {
                prefix_zero++;
                i++;
                continue;
            }
            begin = i;
            bool has_one = false;
            end = end + surfix_zero + 1;
            if(end >= A.size())
                break;
            surfix_zero = 0;
            for(int j = end + 1; j < A.size(); j++) {
                if(A[j] == 0)
                    surfix_zero++;
                else break;
            }
            result += (surfix_zero + 1) * (prefix_zero + 1);
            prefix_zero = 0;
            i = begin + 1;
        }
        return result;
    }
};