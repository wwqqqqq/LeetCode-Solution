class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        for(int i = 0; i < S.size(); i++) {
            if(S[i] == '-') {
                S.erase(S.begin()+i);
                i--;
            }
            else if(S[i] >= 'a' && S[i] <= 'z')
                S[i] = S[i] - 'a' + 'A';
        }
        if(K == 0)
            return S;
        int size = S.size() % K;
        if(size == 0)
            size = K;
        int count = 0;
        for(int i = 0; i < S.size(); i++) {
            count++;
            if(count == size) {
                if(i != S.size()-1) {
                    S.insert(S.begin()+i+1,'-');
                    i++;
                }
                count = 0;
                if(size != K) {
                    size = K;
                }
            }
        }
        return S;
    }
};