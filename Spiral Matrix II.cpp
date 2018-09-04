class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result;
        if(n==0)
            return result;
        
        for(int i=0;i<n;i++) {
            vector<int> tmp(n);
            result.push_back(tmp);
        }
        
        const int right=0, down=1, left=2, up=3;
        int step,i=0,j=-1, x=0, direction;
        int count = 1;
        while(true)
        {
            if(x%2==0) step = n-x/2;
            else step = n-(x+1)/2;
            direction = x%4;
            if(step==0) break;
            x++;
            for(int k=0;k<step;k++)
            {
                if(direction==right) j++;
                else if(direction==down) i++;
                else if(direction==left) j--;
                else i--;
                result[i][j] = count;
                count++;
            }
        }
        return result;
    }
};