bool IsSmaller(pair<int, int> e1, pair<int, int> e2)
{
    return e1.first < e2.first || (e1.first == e2.second && e1.second < e2.second);
}
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        auto env = envelopes;
        int size = envelopes.size();
        if(size==0) return 0;
        int max[size];
        int i,j;
        for(i=0;i<size;i++) max[i]=1;
        
        for(i=0;i<size;i++)
        {
            for(j=size-1;j>i;j--)
            {
                if(IsSmaller(env[j],env[j-1]))
                {
                    auto temp=env[j];
                    env[j]=env[j-1];
                    env[j-1]=temp;
                }
            }
        }
        for(i=size-1;i>=0;i--)
        {
            for(j=i+1;j<size;j++)
            {
                if(env[j].first > env[i].first && env[j].second > env[i].second)
                {
                    int m = 1 + max[j];
                    if(m>max[i]) max[i]=m;
                }
            }
        }
        int m=0;
        for(i=0;i<size;i++)
            if(max[i]>m) m=max[i];
        return m;
    }
};