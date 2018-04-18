class Solution {
public:
    int findNthDigit(int n) {
        long i,temp=0,temp2=1;
        //if(n<10) return n;
        for(i=1;;i++)
        {
            temp=10*temp+1;
            temp2*=10;
            if(temp2*i-temp>=n) break;
        }
        if(temp2*i-temp==n) return 9;
        //i++;
        temp = (temp2/10)*(i-1)-temp/10+1; //position of the first digit of 10^i
        long x=(n-temp)/i+temp2/10;
        //return x;
        long p=(x+1-temp2/10)*i+temp-1;
        //return p;
        for(;p!=n;p--)
        {
            x/=10;
        }
        return x%10;
    }
};