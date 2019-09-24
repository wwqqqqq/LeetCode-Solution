class Solution {
public:
    double minimumDivision(vector<int>& nums, vector<vector<double>>& max_results, vector<vector<double>>& min_results, vector<vector<double>>& max_split, vector<vector<double>>& min_split, int beg, int end) {
        if(beg == end)
            return (double)nums[beg];
        if(beg + 1 == end)
            return (double)nums[beg] / (double)nums[end];
        if(min_results[beg][end] != -1)
            return min_results[beg][end];
        double min = -1;
        int index = -1;
        for(int i = beg; i < end; i++) {
            double divident = minimumDivision(nums, max_results, min_results, max_split, min_split, beg, i);
            double divisor = maximumDivision(nums, max_results, min_results, max_split, min_split, i+1, end);
            double t = divident / divisor;
            if(min == -1 || min > t) {
                min = t;
                index = i;
            }
        }
        min_results[beg][end] = min;
        min_split[beg][end] = index;
        return min;
    }
    double maximumDivision(vector<int>& nums, vector<vector<double>>& max_results, vector<vector<double>>& min_results, vector<vector<double>>& max_split, vector<vector<double>>& min_split, int beg, int end) {
        if(beg == end)
            return (double)nums[beg];
        if(beg + 1 == end)
            return (double)nums[beg] / (double)nums[end];
        if(max_results[beg][end] != -1)
            return max_results[beg][end];
        double max = -1;
        int index = -1;
        for(int i = beg; i < end; i++) {
            double divident = maximumDivision(nums, max_results, min_results, max_split, min_split, beg, i);
            double divisor = minimumDivision(nums, max_results, min_results, max_split, min_split, i+1, end);
            double t = divident / divisor;
            if(max < t) {
                max = t;
                index = i;
            }
        }
        max_results[beg][end] = max;
        max_split[beg][end] = index;
        return max;
    }
    void min_paren(vector<int>& left_paren, vector<int>& right_paren, vector<vector<double>>& max_split, vector<vector<double>>& min_split, int beg, int end) {
        if(beg == end || beg + 1 == end)
            return;
        int index = min_split[beg][end];
        /*if(index > beg) {
            left_paren[beg]++;
            right_paren[index]++;
        }*/
        if(index+1 < end) {
            left_paren[index+1]++;
            right_paren[index]++;
        }
        min_paren(left_paren, right_paren, max_split, min_split, beg, index);
        max_paren(left_paren, right_paren, max_split, min_split, index+1, end);
    }
    void max_paren(vector<int>& left_paren, vector<int>& right_paren, vector<vector<double>>& max_split, vector<vector<double>>& min_split, int beg, int end) {
        if(beg == end || beg + 1 == end)
            return;
        int index = max_split[beg][end];
        /*if(index > beg) {
            left_paren[beg]++;
            right_paren[index]++;
        }*/
        if(index+1 < end) {
            left_paren[index+1]++;
            right_paren[end]++;
        }
        max_paren(left_paren, right_paren, max_split, min_split, beg, index);
        min_paren(left_paren, right_paren, max_split, min_split, index+1, end);
    }
    string optimalDivision(vector<int>& nums) {
        // initialize the maps
        vector<vector<double>> max_results(nums.size(), vector<double>(nums.size(), -1));
        vector<vector<double>> min_results(nums.size(), vector<double>(nums.size(), -1));
        vector<vector<double>> max_split(nums.size(), vector<double>(nums.size(), -1));
        vector<vector<double>> min_split(nums.size(), vector<double>(nums.size(), -1));
        minimumDivision(nums, max_results, min_results, max_split, min_split, 0, nums.size()-1);
        maximumDivision(nums, max_results, min_results, max_split, min_split, 0, nums.size()-1);
        vector<int> left_paren(nums.size(), 0);
        vector<int> right_paren(nums.size(), 0);
        max_paren(left_paren, right_paren, max_split, min_split, 0, nums.size()-1);
        string result;
        for(int i = 0; i < nums.size(); i++) {
            if(left_paren[i] > 0) {
                result.append(left_paren[i],'(');
            }
            result.append(to_string(nums[i]));
            if(right_paren[i] > 0) {
                result.append(right_paren[i],')');
            }
            if(i < nums.size()-1) {
                result.append(1, '/');
            }
        }
        return result;
    }
};