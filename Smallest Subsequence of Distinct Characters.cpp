class Solution {
public:
    string smallestSubsequence(string text, set<char> letters) {
        int count = letters.size();
        if(count == 1) {
            char ch = *(letters.begin());
            string result;
            result.append(1,ch);
            return result;
        }
        set<char> temp1;
        int last = text.size();
        for(int i = text.size() - 1; i >= 0; i--) {
            temp1.insert(text[i]);
            if(temp1.size() == count) {
                last = i + 1;
                break;
            }
        }
        auto iter = letters.begin();
        for(; iter != letters.end(); iter++) {
            int ch = *iter;
            int i = 0;
            for(; i < last; i++) {
                if(text[i] == ch)
                    break;
            }
            if(i >= last) {
                continue;
            }
            set<char> temp;
            for(int j = i+1; j < text.size(); j++) {
                if(text[j] != ch && letters.find(text[j])!=letters.end())
                    temp.insert(text[j]);
            }
            if(temp.size() == count - 1) {
                letters.erase(ch);
                string result;
                result.append(1,ch);
                result.append(smallestSubsequence(text.substr(i+1), letters));
                return result;
            }
        }
        string empty;
        return empty;
    }
    string smallestSubsequence(string text) {
        set<char> letters;
        for(int i = 0; i < text.size(); i++) {
            letters.insert(text[i]);
        }
        return smallestSubsequence(text, letters);
    }
};