class Solution {
public:
    vector<int> grayCode(int n) {
        int i,t=1;
        vector<int> temp;
        vector<long> exp;
        for(i=0;i<n;i++) 
        {
            temp.push_back(i);
            t*=2;
            exp.push_back(t);
        }
        vector<int> result;
        for(i=0;i<t;i++)
        {
            int r=0;
            for(int j=0;j<n;j++)
            {
                int k=i/exp[j];
                k = k%2;
                int m=i%exp[j];
                if(k==0 && m>=exp[j]/2) r+=exp[j]/2;
                else if(k==1 && m<exp[j]/2) r+=exp[j]/2;
            }
            result.push_back(r);
        }
        return result;
    }
};