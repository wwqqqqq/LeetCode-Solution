// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        //return guessn(1,n);
        long low=1,high=n;
        while(low<high)
        {
            /*if(guess(high)!=0) high--;
            else return high;
            if(guess(low)!=0) low++;
            else return low;*/
            long mid=(low+high)/2;
            int r=guess(mid);
            if(r==1)
            {
                low=mid+1;
                
            }
            else if(r==0) return mid;
            else 
            {
                high=mid-1;
            }
            /*if(guess(high)!=0) high--;
            else return high;
            if(guess(low)!=0) low++;
            else return low;*/
        }
        if(low==high) return low;
        return 0;
    }
};