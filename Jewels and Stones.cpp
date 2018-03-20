class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int i, j;
        int count = 0;
        for (i = 0; S[i] != '\0'; i++)
        {
            for (j = 0; J[j] != '\0'; j++)
                if (S[i] == J[j])
                {
                    count ++;
                    break;
                }
        }
        return count;
    }
};