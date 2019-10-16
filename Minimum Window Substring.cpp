class Solution {
public:
    int find(vector<int>& arr, int e) {
        // find the location of e in arr
        // arr is a sorted vector
        int st = 0, ed = arr.size()-1;
        if(arr.size() == 0 || e > arr[ed])
            return -1;
        while(st <= ed) {
            if(st == ed && arr[st] == e)
                return st;
            int mid = (st + ed) / 2;
            if(arr[mid] == e)
                ed = mid;
            else if(arr[mid] < e)
                st = mid + 1;
            else ed = mid - 1;
        }
        return -1;
    }
    string minWindow(string s, string t) {
        // the time complexity is O(n^2 logk), where n is the size of s, k is the size of t
        /*set<char> characters;
        string result;
        for(int i = 0; i < t.size(); i++) characters.insert(t[i]);
        for(int st = 0; st < s.size(); st++) {
            set<char> temp;
            for(int ed = st; ed < s.size(); ed++) {
                if(characters.find(s[ed]) != characters.end()) {
                    // s[ed] is in string t
                    temp.insert(s[ed]);
                    if(temp.size() == characters.size()) {
                        // then nums[st..ed] contain all the characters in T
                        int len = ed - st + 1;
                        if(result.size() == 0 || result.size() > len) {
                            result.erase(result.begin(), result.end());
                            result.append(s.substr(st, len));
                        }
                    }
                }
            }
        }
        return result;*/
        // will T consists of repeated elements?
        // time complexity is O(nlogn)
        vector<int> require(128, false); // appears[i] is how many times (char)i appears in t
        vector<vector<int>> count(128, vector<int>(s.size(), 0)); // count[i][j] is how many times (char)i appears in s[0..j]
        for(int i = 0; i < t.size(); i++)
            require[t[i]]++;
        for(int c = 0; c < 128; c++) {
            if(require[c] == 0)
                continue;
            for(int i = 0; i < s.size(); i++) {
                if(s[i] != c) {
                    count[c][i] = (i==0)?0:count[c][i-1];
                    continue;
                }
                if(i == 0)
                    count[c][i] = 1;
                else count[c][i] = count[c][i-1] + 1;
            }
        }
        int min = 0;
        int start = 0;
        for(int st = 0; st < s.size(); st++) {
            if(require[s[st]] == 0)
                continue;
            // use this loop to determine the starting point of the substring
            // for any character c, we know how many times c appear before s[st] (count[c][st-1])
            // so the next location that c appears in s is next = find(count[c], count[c][st-1]+1)
            // is count[c][st-1]+1 doesn't exist, then there is no more c after s[st-1], so this substring is unavailable
            // otherwise, the length of the substring is max(len, next-st+1)
            int length = 0;
            bool valid = true;
            for(int c = 0; c < 128; c++) {
                if(require[c] == 0)
                    continue;
                int next = find(count[c], ((st==0)?0:(count[c][st-1])) + require[c]);
                if(next == -1) {
                    valid = false;
                    break;
                }
                if(length < next - st + 1) length = next - st + 1;
            }
            if(!valid)
                break;
            if(min == 0 || length < min) {
                min = length;
                start = st;
            }
        }
        return s.substr(start, min);
    }
};