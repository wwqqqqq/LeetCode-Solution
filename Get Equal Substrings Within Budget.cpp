class Solution {
public:
    int abs(int n) {
        if(n < 0)
            return -n;
        return n;
    }
    /*int maxChange(vector<int>& diff, int begin, int maxCost) {
        if(begin >= diff.size() || maxCost == 0)
            return 0;
        if(diff[begin] > maxCost)
            return maxChange(diff, begin+1, maxCost);
        // take diff[begin]
        int result1 = maxChange(diff, begin+1, maxCost - diff[begin]) + 1;
        // do not take diff[begin]
        int result2 = maxChange(diff, begin+1, maxCost);
        if(result1 > result2)
            return result1;
        return result2;
    }
    int equalSubstring(string s, string t, int maxCost) {
        if(maxCost == 0)
            return 0;
        vector<int> diff;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == t[i])
                continue;
            diff.push_back(abs(s[i] - t[i]));
        }
        if(diff.size() == 0)
            return 0;
        return maxChange(diff, 0, maxCost);
    }*/
    int equalSubstring(string s, string t, int begin, int maxCost) {
        // if include s[0] and t[0]
        int max = maxCost;
        int result1 = s.size() - begin;
        for(int i = begin; i < s.size(); i++) {
            int diff = abs(s[i] - t[i]);
            if(max < diff) {
                result1 = i;
                break;
            }
            max = max - diff;
        }
        if(result1 == s.size()-begin)
            return result1;
        // do not include s[0] and t[0]
        int result2 = equalSubstring(s, t, begin+1, maxCost);
        if(result1 < result2)
            return result2;
        return result1;
    }
    int equalSubstring(string s, string t, int maxCost) {
        //return equalSubstring(s, t, 0, maxCost);
        /*int result = 0;
        for(int i = 0; i < s.size(); i++) {
            if(i != 0 && s[i-1] == t[i-1])
                continue;
            int max = maxCost;
            int temp = s.size() - i;
            for(int j = i; j < s.size(); j++) {
                int diff = abs(s[j] - t[j]);
                if(max < diff) {
                    temp = i;
                    break;
                }
                max = max - diff;
            }
            if(temp > result)
                result = temp;
            if(result == s.size()-i)
                return result;
        }
        return result;*/
        int beg = 0;
        int end = -1;
        int max = maxCost;
        for(int i = 0; i < s.size(); i++) {
            int diff = abs(s[i] - t[i]);
            if(diff <= maxCost) {
                beg = i;
                end = i;
                break;
            }
        }
        if(beg != end)
            return 0;
        for(int i = beg; i < t.size(); i++) {
            int diff = abs(s[i] - t[i]);
            if(diff > max) {
                break;
            }
            end = i;
            max = max - diff;
        }
        int result = end - beg + 1;
        while(end < t.size() && beg < t.size()) {
            max += abs(s[beg] - t[beg]);
            beg++;
            if(beg >= t.size())
                break;
            for(int i = end+1; i < t.size(); i++) {
                int diff = abs(s[i] - t[i]);
                if(diff > max)
                    break;
                end = i;
                max = max - diff;
            }
            if(end - beg + 1 > result)
                result = end - beg + 1;
            if(end >= t.size() - 1)
                break;
            if(abs(s[end+1] - t[end+1]) > maxCost) {
                beg = end + 1;
                end = end + 1;
                max = maxCost - abs(s[beg] - t[beg]);
            }
        }
        return result;
    }
};