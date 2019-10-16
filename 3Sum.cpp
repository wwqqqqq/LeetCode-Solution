class Solution {
public:
    bool find(vector<int>& arr, int st, int ed, int k) {
        while(st <= ed) {
            int mid = (st + ed) / 2;
            if(arr[mid] == k)
                return true;
            else if(arr[mid] < k)
                st = mid + 1;
            else ed = mid - 1;
        }
        return false;
    }
    vector<vector<int>> twoSum(vector<int>& nums, int k, int st) {
        vector<vector<int>> result;
        for(int i = st; i + 1 < nums.size(); i++) {
            if(i > st && nums[i] == nums[i-1])
                continue;
            if(nums[i] * 2 > k)
                break;
            if(find(nums, i+1, nums.size()-1, k-nums[i])) {
                vector<int> temp = {nums[i], k-nums[i]};
                result.push_back(temp);
            }
        }
        return result;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0; i + 2 < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            vector<vector<int>> temp = twoSum(nums, -nums[i], i+1);
            for(int j = 0; j < temp.size(); j++) {
                vector<int> t = temp[j];
                t.insert(t.begin(), nums[i]);
                result.push_back(t);
            }
        }
        return result;
    }
};