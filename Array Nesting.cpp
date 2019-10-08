class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<int> group(nums.size(), -1);
        int max = 0;
        int group_count = 0;
        vector<int> group_size;
        for(int i = 0; i < nums.size(); i++) {
            if(group[i] != -1)
                continue;
            int count = 0;
            while(group[i] == -1) {
                group[i] = group_count;
                i = nums[i];
                count++;
            }
            if(group[i] != group_count) {
                count += group_size[group[i]];
            }
            if(count > max)
                max = count;
            group_size.push_back(count);
            group_count++;
        }
        return max;
    }
};