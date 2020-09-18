class Solution
{
public:
    int max(int a, int b)
    {
        return (a < b) ? b : a;
    }
    int min(int a, int b)
    {
        return (a < b) ? a : b;
    }
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates)
    {
        vector<int> increments(length + 1, 0);
        vector<int> result(length, 0);
        for (int i = 0; i < updates.size(); i++)
        {
            int startIndex = max(0, updates[i][0]);
            int endIndexPlusOne = min(length, updates[i][1] + 1);
            int inc = updates[i][2];
            increments[startIndex] += inc;
            increments[endIndexPlusOne] -= inc;
        }
        int last = 0;
        for (int i = 0; i < length; i++)
        {
            result[i] = last + increments[i];
            last = result[i];
        }
        return result;
    }
};