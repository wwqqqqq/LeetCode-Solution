class Solution {
public:
    int m[100][100];
    int RS(string ring, string key, int last)
    {
        if(key.size()==0) return 0;
        if(m[key.size()-1][last]!=-1) return m[key.size()-1][last];
        string next=key.substr(1,key.size()-1);
        char c=key[0];
        if(ring[last]==c)
        {
            m[key.size()-1][last]=RS(ring,next,last);
            return m[key.size()-1][last];
        }
        int len=ring.size();
        int min_step=len*(key.size());
        bool getl=false;
        bool getr=false;
        for(int j=0;2*j<=len;j++)
        {
            int left=(last-j+len)%len;
            int right=(last+j)%len;;
            if(getl==false)
            {
                if(ring[left]==c)
                {
                    int step=j+RS(ring,next,left);
                    if(step<min_step) min_step=step;
                    getl=true;
                } 
            }
            if(getr==false)
            {
                if(ring[right]==c)
                {
                    getr=true;
                    if(right!=left)
                    {
                        int step=j+RS(ring,next,right);
                        if(step<min_step) min_step=step;
                    }
                }
            }
            if(getl==true&&getr==true) break;
        }
        m[key.size()-1][last]=min_step;
        return min_step;
    }
    int findRotateSteps(string ring, string key) {
        for(int i=0;i<100;i++)
            for(int j=0;j<100;j++)
                m[i][j]=-1;
        return RS(ring,key,0)+key.size();
    }
};