class Solution {
public:
    void addnum(set<int>& sums, int n, int limit) {
        set<int> temp;
        temp.insert(n);
        for(auto iter=sums.begin(); iter != sums.end(); iter++){
            if(*iter + n <= limit)
                temp.insert(*iter + n);
        }
        for(auto iter=temp.begin(); iter != temp.end(); iter++)
            sums.insert(*iter);
    }
    void allsums(vector<int>& nums, int limit, set<int>& sums) {
        for(int i = 0; i < nums.size(); i++) {
            addnum(sums, nums[i], limit);
        }
        sums.insert(0);
    }
    int minPatches(vector<int>& nums, set<int> &sums, int beg, int ed) {
        for(int i = ed; i >= beg; i--) {
            if(sums.find(i) != sums.end())
                continue;
            vector<int> choices;
            for(auto iter=sums.begin(); iter!=sums.end(); iter++)
                if(*iter < i)
                    choices.push_back(i - *iter);
                else break;
            int result = ed;
            for(auto iter=choices.end()-1; iter>=choices.begin(); iter--) {
                set<int> temp(sums);
                addnum(temp, *iter, i);
                int count = minPatches(nums, temp, beg, i-1);
                if(count < result) result = count + 1;
                if(count == 0)
                    return 1;
            }
            return result;
        }
        return 0;
    }
    int minPatches(vector<int>& nums, int n) {
        set<int> sums;
        allsums(nums, n, sums);
        return minPatches(nums, sums, 1, n);
        /*int count = 0;
        for(int i = n; i >= 1; i--) {
            if(sums.find(i) != sums.end())
                continue;
            int newnum = i;
            for(auto iter=sums.begin(); iter != sums.end(); iter++)
                if(*iter < i)
                    newnum = i - *iter;
                else break;
            addnum(sums, newnum, n);
            count++;
        }
        return count;*/
    }
};