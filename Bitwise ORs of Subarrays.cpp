class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        set<int> s;
        /*for(int i = 0; i < A.size(); i++) {
            int r = A[i];
            for(int j = i; j < A.size(); j++) {
                r = r | A[j];
                s.insert(r);
            }
        }*/
        set<int> temp1, temp2;
        for(int i = 0; i < A.size(); i++) {
            if(i != 0 && A[i] == A[i-1])
                continue;
            if(A[i] == 0) {
                s.insert(0);
                continue;
            }
            temp2 = {A[i]};
            s.insert(A[i]);
            for(auto iter = temp1.begin(); iter != temp1.end(); iter++) {
                int r = (*iter) | A[i];
                if(temp2.insert(r).second)
                    s.insert(r);
            }
            temp1 = temp2;
            //s.insert(temp2.begin(), temp2.end());
        }
        return s.size();
    }
};