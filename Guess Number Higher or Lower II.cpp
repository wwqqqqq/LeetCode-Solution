class Solution {
public:
    int getMinAmount(int **m,int beg,int ed)
    {
        if(beg>=ed) return 0;
        if(m[beg-1][ed-1]!=-1) return m[beg-1][ed-1];
        int min=(beg+ed)*(ed-beg+1)/2;
        for(int choose=beg;choose<=ed;choose++)
        {
            int count=choose;
            int t1=getMinAmount(m,beg,choose-1);
            int t2=getMinAmount(m,choose+1,ed);
            count+=(t1>t2)?t1:t2;
            if(count<min) min=count;
        }
        m[beg-1][ed-1]=min;
        return min;
    }
    int getMoneyAmount(int n) {
        int** m;
        m=(int**)malloc(n*sizeof(int*));
        for(int i=0;i<n;i++)
        {
            m[i]=(int*)malloc(n*sizeof(int));
            m[i][i]=0;
            for(int j=i+1;j<n;j++)
                m[i][j]=-1;
        }
        int result = getMinAmount(m,1,n);
        for(int i=0;i<n;i++)
            free(m[i]);
        free(m);
        return result;
    }
};