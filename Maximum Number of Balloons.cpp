class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> count(26, 0);
        for(int i = 0; i < text.size(); i++) {
            count[text[i]-'a']++;
        }
        int result = count['b'-'a'];
        if(result > count['a'-'a'])
            result = count[0];
        if(result > count['n'-'a'])
            result = count['n'-'a'];
        if(result * 2 > count['l'-'a'])
            result = count['l' - 'a'] / 2;
        if(result * 2 > count['o' - 'a'])
            result = count['o' - 'a'] / 2;
        return result;
    }
};