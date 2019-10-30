class Solution {
public:
    static int getFirstWordIndex(string log) {
        bool firstWord = true;
        for(int i = 0; i < log.size(); i++) {
            if(log[i] != ' ' && (i == 0 || log[i-1] == ' ')) {
                if(firstWord)
                    firstWord = false;
                else return i;
            }
        }
        return -1;
    }
    bool isLetterLog(string log) {
        char c = log[getFirstWordIndex(log)];
        if(c <= 'z' && c >= 'a')
            return true;
        return false;
    }
    static bool logCompare(string log1, string log2) {
        int i1 = getFirstWordIndex(log1);
        int i2 = getFirstWordIndex(log2);
        for(; i1 < log1.size() && i2 < log2.size(); i1++, i2++) {
            if(log1[i1] != log2[i2])
                return log1[i1] < log2[i2];
        }
        if(i1 < log1.size())
            return false;
        if(i2 < log2.size())
            return true;
        // tie!!
        for(i1 = 0, i2 = 0; i1 < log1.size() && i2 < log2.size(); i1++, i2++) {
            if(log1[i1] != log2[i2])
                return log1[i1] < log2[i2];
        }
        return false;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        int i = logs.size()-1, j = logs.size();
        for(; i >= 0; i--) {
            if(!isLetterLog(logs[i])) {
                j--;
                if(j != i) {
                    string temp = logs[i];
                    logs[i] = logs[j];
                    logs[j] = temp;
                }
            }
        }
        // j is the index of the first digit-log
        sort(logs.begin(), logs.begin()+j, logCompare);
        return logs;
    }
};