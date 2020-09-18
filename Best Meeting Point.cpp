class Solution
{
public:
    int abs(int n)
    {
        return (n < 0) ? (-n) : n;
    }
    int find(vector<int> &array, int num)
    {
        int start = 0;
        int end = array.size() - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (array[mid] == num)
            {
                return mid;
            }
            if (array[mid] > num)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return start;
    }
    void sortedInsert(vector<int> &array, int num)
    {
        int index = find(array, num);
        array.insert(array.begin() + index, num);
    }
    int minTotalDistance(vector<vector<int>> &grid)
    {
        vector<int> x;
        vector<int> y;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    sortedInsert(x, i);
                    sortedInsert(y, j);
                }
            }
        }
        int num = x.size();
        int x_median = x[num / 2];
        int y_median = y[num / 2];
        int result = 0;
        for (int i = 0; i < num; i++)
        {
            result += abs(x_median - x[i]) + abs(y_median - y[i]);
        }
        return result;
    }
};