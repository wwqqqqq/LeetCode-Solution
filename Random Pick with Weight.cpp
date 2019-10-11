class Solution {
public:
    vector<int> weight;
    int max = 0;
    Solution(vector<int>& w) {
        weight.insert(weight.end(), w.begin(), w.end());
        for(int i = 1; i < weight.size(); i++)
            weight[i] = weight[i] + weight[i-1];
        max = weight[weight.size()-1];
        srand((unsigned)time(NULL));
    }
    int determinePick(int randInt, int low, int high) {
        if(low == high)
            return low;
        int mid = (low + high) / 2;
        if(randInt <= weight[mid])
            high = mid;
        else low = mid + 1;
        return determinePick(randInt, low, high);
    }
    int pickIndex() {
        int r = rand() % max + 1;
        //return r;
        return determinePick(r, 0, weight.size()-1);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */