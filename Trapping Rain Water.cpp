class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 1)
            return 0;
        int result = 0;
        for(int i = 1; i < height.size(); i++) {
            if(height[i] >= height[i-1])
                continue;
            int h = height[i-1];
            bool trap = false;
            for(int j = i+1; j < height.size(); j++) {
                if(height[j] >= h) {
                    trap = true;
                    break;
                }
            }
            if(trap) {
                for(int j = i; j < height.size(); j++) {
                    if(height[j] >= h)
                        break;
                    result += h - height[j];
                    height[j] = h;
                }
            }
        }
        for(int i = height.size()-2; i  >= 0; i--) {
            if(height[i] >= height[i+1])
                continue;
            int h = height[i+1];
            bool trap = false;
            for(int j = i-1; j >= 0; j--) {
                if(height[j] > h) {
                    trap = true;
                    break;
                }
            }
            if(trap) {
                for(int j = i; j >= 0; j--)  {
                    if(height[j] > h)
                        break;
                    result += h - height[j];
                    height[j] = h;
                }
            }
        }
        return result;
        /* METHOD2: can get the right answer, but time complexity is too high
        int min = height[0];
        int max = height[0];
        int sum0 = 0;
        for(int i = 0; i < height.size(); i++) {
            if(height[i] < min) min = height[i];
            if(height[i] > max) max = height[i];
            sum0 += height[i];
        }
        for(int h = min+1; h <= max; h++) {
            for(int i = 1; i < height.size(); i++) {
                if(height[i] +1 == h && height[i] < height[i-1]) {
                    bool trap = false;
                    for(int j = i+1; j < height.size(); j++) {
                        if(height[j] < height[i])
                            break;
                        if(height[j] > height[i]) {
                            trap = true;
                            break;
                        }
                    }
                    if(trap) {
                        for(int j = i + 1; j < height.size(); j++) {
                            if(height[j] == height[i])
                                height[j]++;
                            else break;
                        }
                        height[i]++;
                    }
                }
            }
        }
        int sum = 0;
        for(int i = 0; i < height.size(); i++)
            sum += height[i];
        return sum - sum0;*/
        /* WRONG ANSWER
        int i = 0;
        int result = 0;
        while(i < height.size()) {
            int sum = 0;
            int j = i + 1;
            for(; j < height.size(); j++) {
                sum += height[j];
                if(height[j] > height[j-1])
                    break;
            }
            if(j >= height.size())
                break;
            if(j == i+1) {
                i++;
                continue;
            }
            for(j++; j < height.size(); j++) {
                if(height[j] < height[j-1])
                    break;
                sum += height[j];
            }
            j--;
            sum -= height[j];
            result += (min(height[i],height[j]) * (j-i-1)) - sum;
            i = j;
        }
        return result;*/
    }
};