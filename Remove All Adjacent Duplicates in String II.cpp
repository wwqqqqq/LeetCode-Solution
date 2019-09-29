class Solution {
public:
    string merge(string& s1, string& s2, int k) {
        if(s1.size() == 0)
            return s2;
        if(s2.size() == 0)
            return s1;
        if(s1[s1.size()-1] != s2[0]) {
            s1.append(s2);
            return s1;
        }
        int count1 = 0;
        int count2 = 0;
        for(int i = s1.size() - 1; i >= 0; i--)
            if(s1[i] == s2[0])
                count1++;
            else break;
        for(int i = 0; i < s2.size(); i++)
            if(s2[i] == s2[0])
                count2++;
            else break;
        if(count1 + count2 < k) {
            s1.append(s2);
            return s1;
        }
        count2 = k - count1;
        if(count2 < 0)
            count2 = 0;
        s1 = s1.substr(0, s1.size() - count1);
        s2 = s2.substr(count2);
        return merge(s1, s2, k);
    }
    string removeDuplicates(string s, int k) {
        if(k > s.size())
            return s;
        if(k == 1)
            return "";
        if(k == s.size()) {
            for(int i = 1; i < s.size(); i++)
                if(s[i] != s[0])
                    return s;
            return "";
        }
        int len = s.size();
        int mid = len / 2;
        // first half: 0 - mid-1
        // second half: mid - k.size()-1
        string first_half = removeDuplicates(s.substr(0, mid), k);
        string second_half = removeDuplicates(s.substr(mid), k);
        return merge(first_half, second_half, k);
    }
};