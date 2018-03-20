class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        if(m==0) return result;
        int n = matrix[0].size();
        if(n==0) return result;
        
        const int right=0, down=1, left=2, up=3;
        int step,i=0,j=-1, x=0, direction;
        int size=m*n;
        while(true)
        {
            if(x%2==0) step = n-x/2;
            else step = m-(x+1)/2;
            direction = x%4;
            if(step==0) break;
            x++;
            for(int k=0;k<step;k++)
            {
                if(direction==right) j++;
                else if(direction==down) i++;
                else if(direction==left) j--;
                else i--;
                result.push_back(matrix[i][j]);
                //count++;
            }
        }
        return result;
    }
};