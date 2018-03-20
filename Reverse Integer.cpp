class Solution {
public:
    int reverse(int x) {
        int sign=1;
        int max = (~0)-(1<<(8*sizeof(int)-1));
        if(x<0)
        {
            sign=-1;
            x=-x;
        }
        int res=0;
        while(x!=0)
        {
            if(max/10<res) return 0;
            res*=10;
            if(sign==1&&max-x%10<res) return 0;
            else if(sign==-1&&max-x%10<res-1) return 0;
            res+=x%10;
            x/=10;
        }
        return sign*res;
    }
};