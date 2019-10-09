class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> count(121, 0);
        for(int i = 0; i < ages.size(); i++)
            count[ages[i]]++;
        int sum = 0;
        for(int i = 0; i < ages.size(); i++) {
            int low = ages[i] / 2 + 7;
            for(int j = low+1; j <= ages[i]; j++)
                sum += count[j];
            if(low+1 <= ages[i])
                sum--;
        }
        return sum;
    }
    /*int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int count = 0;
        for(int i = 0; i < ages.size(); i++) {
            int high_bound = i+1;
            while(high_bound < ages.size()) {
                if(ages[high_bound] > ages[i])
                    break;
                high_bound++;
            }
            int low_bound = 0;
            int min = ages[i] / 2 + 7;
            while(low_bound < high_bound - 1) {
                if(ages[low_bound] > min)
                    break;
                low_bound++;
            }
            count += high_bound - low_bound - 1;
        }
        return count;
    }*/
};