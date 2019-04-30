class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int> count(limit+1, 0);
        for(int i = 0; i < people.size(); i++) {
            count[people[i]]++;
        }
        int result = 0;
        int i = 1;
        while(i <= limit && count[i] == 0)
            i++;
        if(i > limit)
            return people.size();
        int j = limit;
        while(j >= i && count[j] == 0)
            j--;
        while(i <= j) {
            if(i == j) {
                if(i + j <= limit) {
                    result += count[i] / 2 + count[i] % 2;
                }
                else result += count[i];
                break;
            }
            if(i + j <= limit) {
                if(count[i] < count[j]) {
                    result += count[i];
                    count[j] -= count[i];
                    count[i] = 0;
                    while(i <= j && count[i] == 0)
                        i++;
                }
                else if(count[i] == count[j]) {
                    result += count[i];
                    count[i] = 0;
                    count[j] = 0;
                    while(i <= j && count[i] == 0)
                        i++;
                    if(i > j)
                        return result;
                    while(j >= i && count[j] == 0)
                        j--;
                }
                else {
                    result += count[j];
                    count[i] -= count[j];
                    count[j] = 0;
                    while(j >= i && count[j] == 0)
                        j--;
                }
            }
            else {
                // i + j > limit
                result += count[j];
                count[j] = 0;
                while(j >= i && count[j] == 0)
                    j--;
            }
        }
        /*for(int i = 1; i <= limit / 2; i++) {
            int expect = limit - i;
            for(int j = expect+1; j <= limit; j++) {
                result += count[j];
                count[j] = 0;
            }
            while(count[i] > 0) {
                while(expect > i && count[expect] == 0)
                    expect--;
                if(expect <= i)
                    break;
                if(count[expect] >= count[i]) {
                    count[expect] -= count[i];
                    result += count[i];
                    count[i] = 0;
                }
                else {
                    count[i] -= count[expect];
                    result += count[expect];
                    count[expect] = 0;
                }
            }
            if(count[i] > 0) {
                if(i * 2 <= limit)
                    result += count[i] / 2;
                if(count[i] % 2 == 1)
                    result++;
                count[i] = 0;
            }
        }
        for(int i = 1; i <= limit; i++)
            result += count[i];*/
        return result;
    }
    /*int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int count = 0;
        while(people.size() > 0) {
            int expect = limit - people[0];
            if(expect <= 0 || expect < people[0])
                return count + people.size();
            int i;
            for(i = people.size() - 1; i > 0; i--) {
                if(people[i] <=expect) {
                    people.erase(people.begin() + i);
                    people.erase(people.begin());
                    count++;
                    break;
                }
            }
            if(i == 0)
                return count + people.size();
        }
        return count;
    }*/
};