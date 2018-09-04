class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> result;
        if(R==0 || C==0)
            return result;
        
        const int right=0, down=1, left=2, up=3;
        int i=r0, j=c0, x=0;
        vector<int> tmp = {r0, c0};
        result.push_back(tmp);
        int count = 1;
        while(count<R*C)
        {
            int step = (int)(x/2) + 1;
            int direction = x%4;
            x++;
            for(int k=0;k<step;k++)
            {
                if(direction==right) j++;
                else if(direction==down) i++;
                else if(direction==left) j--;
                else i--;
                if(i>=0 && i<R && j>=0 && j<C) {
                    vector<int> temp = {i, j};
                    result.push_back(temp);
                    count++;
                    if(count>=R*C)
                        break;
                }
            }
            if(count>=R*C)
                break;
        }
        return result;
    }
};