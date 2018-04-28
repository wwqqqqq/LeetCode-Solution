class Solution {
public:
    int maximumSwap(int num) {
        if(num==0) return 0;
        vector<int> number;
        int result=num;
        while(num!=0) 
        {
            number.insert(number.begin(),num%10);
            num/=10;
        }
        int i;
        for(i=0;i<number.size();i++)
        {
            int m=i;
            for(int beg=i+1;beg<number.size();beg++)
            {
                if(number[beg]>=number[m]) m=beg;
            }
            if(number[m]>number[i])
            {
                int temp=number[m];
                number[m]=number[i];
                number[i]=temp;
                break;
            }
        }
        if(i==number.size()) return result;
        result=0;
        for(i=0;i<number.size();i++)
        {
            result*=10;
            result+=number[i];
        }
        return result;
    }
};