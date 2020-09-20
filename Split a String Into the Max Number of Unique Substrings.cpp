class Solution
{
public:
    int maxUniqueSplit(string s, set<string> &splits)
    {
        if (s.size() == 0)
        {
            return 0;
        }
        int maxResult = -1;
        for (int i = 0; i < s.size(); i++)
        {
            string sub1 = s.substr(0, i + 1);
            string sub2 = s.substr(i + 1);
            if (splits.find(sub1) == splits.end())
            {
                splits.insert(sub1);
                int result = maxUniqueSplit(sub2, splits);
                if (result != -1 && maxResult < (result + 1))
                {
                    maxResult = result + 1;
                }
                splits.erase(sub1);
            }
        }
        return maxResult;
    }
    int maxUniqueSplit(string s)
    {
        set<string> splits;
        return maxUniqueSplit(s, splits);
    }
};