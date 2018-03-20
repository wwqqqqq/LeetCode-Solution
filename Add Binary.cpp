class Solution {
public:
    string addBinary(string a, string b) {
        int sizea=a.size();
        int sizeb=b.size();
        int size=((sizea>sizeb)?sizea:sizeb)+1;
        int i;
        int reva[sizea];
        int revb[sizeb];
        int revc[size];
        for(i=0;i<sizea;i++)
        {
            reva[i]=a[sizea-1-i]-'0';
        }
        for(i=0;i<sizeb;i++)
        {
            revb[i]=b[sizeb-1-i]-'0';
        }
        revc[0]=0;
        for(i=0;i<size-1;i++)
        {
            int x;
            if(i<sizea&&i<sizeb)
                x = revc[i]+reva[i]+revb[i];
            else if(i>=sizea&&i<sizeb)
                x = revc[i]+revb[i];
            else if(i>=sizea&&i>=sizeb)
                x = revc[i];
            else
                x = revc[i]+reva[i];
            if(x==0)
            {
                revc[i]=0;
                revc[i+1]=0;
            }
            else if(x==1)
            {
                revc[i]=1;
                revc[i+1]=0;
            }
            else if(x==2)
            {
                revc[i]=0;
                revc[i+1]=1;
            }
            else if(x==3)
            {
                revc[i]=1;
                revc[i+1]=1;
            }
        }
        char c[size+1];
        int j;
        for(i=0,j=size-1;i<size,j>=0;j--)
        {
            if(i==0&&revc[j]==0)
                continue;
            c[i]=revc[j]+'0';
            i++;
        }
        if(i==0) return "0";
        c[i]='\0';
        return c;
    }
};