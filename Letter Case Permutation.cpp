class Solution {
public:
    vector<string> LCP2(string S, set<int>& index) {
        vector<string> result;
        if(index.size()==0) {
            result.push_back(S);
            return result;
        }
        int ind = *index.begin();
        index.erase(index.begin());
        vector<string> tmp = LCP2(S,index);
        for(int i=0;i<tmp.size();i++) {
            result.push_back(tmp[i]);
            tmp[i][ind] += 'A' - 'a';
            result.push_back(tmp[i]);
        }
        return result;
    }
    vector<string> letterCasePermutation(string S) {
        set<int> index;
        for(int i=0;i<S.size();i++) {
            if(S[i]>='a'&&S[i]<='z') {
                index.insert(i);
            }
            else if(S[i]>='A'&&S[i]<='Z') {
                index.insert(i);
                S[i] = S[i] + 'a' - 'A';
            }
        }
        return LCP2(S, index);
    }
};