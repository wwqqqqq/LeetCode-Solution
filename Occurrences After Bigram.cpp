class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> result;
        for(int i = 0; i < text.size(); i++) {
            if(text[i] != first[0])
                continue;
            if(i != 0 && text[i-1] != ' ')
                continue;
            // match the first word
            int j = i + 1;
            for(; j - i < first.size(); j++) {
                if(text[j] != first[j-i])
                    break;
            }
            if(j - i < first.size())
                continue;
            // spaces
            if(j >= text.size() || text[j] != ' ')
                continue;
            while(text[j] == ' ')
                j++;
            // match the second word
            int k = j;
            for(; k - j < second.size(); k++) {
                if(text[k] != second[k-j])
                    break;
            }
            if(k - j < second.size())
                continue;
            // spaces
            if(k >= text.size() || text[k] != ' ')
                continue;
            while(text[k] == ' ')
                k++;
            int beg = k;
            int end = k;
            for(k++; k < text.size(); k++) {
                if(text[k] == ' ')
                    break;
                end = k;
            }
            result.push_back(text.substr(beg, end-beg+1));
        }
        return result;
    }
};