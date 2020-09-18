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
    int findIndex(vector<vector<int>> &intervals, int num)
    {
        // return the index of updates or the place where it should be inserted to
        int begin = 0;
        int end = intervals.size() - 1;
        while (begin <= end)
        {
            int mid = (begin + end) / 2;
            int startInd = intervals[mid][0];
            int endInd = intervals[mid][1];
            if (num >= startInd && num <= endInd)
            {
                return mid;
            }
            else if (num < startInd)
            {
                end = mid - 1;
            }
            else
            {
                begin = mid + 1;
            }
        }
        return begin;
    }
    void mergeUpdates(vector<vector<int>> &updates, int startIndex, int endIndex, int inc)
    {
        if (startIndex > endIndex || inc == 0)
            return;
        int leftUpdateIndex = findIndex(updates, startIndex);
        int rightUpdateIndex = findIndex(updates, endIndex);
        if (leftUpdateIndex >= updates.size())
        {
            updates.push_back({startIndex, endIndex, inc});
            return;
        }
        if (rightUpdateIndex == 0 && endIndex < updates[0][0])
        {
            updates.insert(updates.begin(), {startIndex, endIndex, inc});
            return;
        }
        for (int i = leftUpdateIndex; i <= rightUpdateIndex && startIndex <= endIndex; i++)
        {
            if (i >= updates.size())
            {
                updates.push_back({startIndex, endIndex, inc});
                return;
            }
            int prevStartIndex = updates[i][0];
            int prevEndIndex = updates[i][1];
            int prevInc = updates[i][2];
            if (endIndex < prevStartIndex)
            {
                updates.insert(updates.begin() + i, {startIndex, endIndex, inc});
                return;
            }
            if (prevStartIndex > startIndex)
            {
                updates.insert(updates.begin() + i, {startIndex, prevStartIndex - 1, inc});
                startIndex = prevStartIndex;
                rightUpdateIndex++;
                i++;
            }
            if (prevStartIndex < startIndex)
            {
                updates[i][1] = startIndex - 1;
                i++;
                updates.insert(updates.begin() + i, {startIndex, prevEndIndex, inc});
                prevStartIndex = startIndex;
                rightUpdateIndex++;
            }
            if (prevStartIndex == startIndex)
            {
                if (endIndex >= prevEndIndex)
                {
                    updates[i][2] = prevInc + inc;
                    startIndex = prevEndIndex + 1;
                    continue;
                }
                else
                {
                    updates[i][1] = endIndex;
                    updates[i][2] = prevInc + inc;
                    updates.insert(updates.begin() + i + 1, {endIndex + 1, prevEndIndex, prevInc});
                    return;
                }
            }
        }
    }
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates)
    {
        vector<int> result(length, 0);
        vector<vector<int>> mergedUpdates;
        for (int i = 0; i < updates.size(); i++)
        {
            int startIndex = max(0, updates[i][0]);
            int endIndex = min(length - 1, updates[i][1]);
            int inc = updates[i][2];
            mergeUpdates(mergedUpdates, startIndex, endIndex, inc);
        }
        for (int i = 0; i < mergedUpdates.size(); i++)
        {
            int inc = mergedUpdates[i][2];
            if (inc != 0)
            {
                for (int j = mergedUpdates[i][0]; j <= mergedUpdates[i][1]; j++)
                {
                    result[j] += inc;
                }
            }
        }
        return result;
    }
};