class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int min = arr[arr.size()-1] - arr[0];
        for(int i = 0; i + 1 < arr.size(); i++) {
            if(arr[i+1] - arr[i] < min)
                min = arr[i+1] - arr[i];
        }
        vector<vector<int>> result;
        for(int i = 0; i + 1 < arr.size(); i++) {
            if(arr[i+1] - arr[i] == min) {
                vector<int> temp = {arr[i], arr[i+1]};
                result.push_back(temp);
            }
        }
        return result;
    }
};