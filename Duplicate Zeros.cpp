class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> zeros(arr.size(), 0);
        int count = 0;
        for(int i = 0; i < arr.size(); i++) {
            zeros[i] = count;
            if(arr[i] == 0)
                count++;
        }
        if(count == 0)
            return;
        for(int i = arr.size()-1; i >= 0; i--) {
            int new_loc = i + zeros[i];
            if(new_loc >= arr.size())
                continue;
            arr[new_loc] = arr[i];
            if(arr[i] == 0 && new_loc+1 < arr.size())
                arr[new_loc+1] = 0;
        }
    }
};