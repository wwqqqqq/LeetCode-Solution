class Solution {
public:
    bool findsequence(map<int,int> m)
    {
        if(m.size()==0) return true;
        if(m.size()<3) return false;
        int i=m.begin()->first;
        m[i]--;
        if(m[i]==0) m.erase(i);
        if(m.find(i+1)==m.end()) return false;
        m[i+1]--;
        if(m[i+1]==0) m.erase(i+1);
        if(m.find(i+2)==m.end()) return false;
        m[i+2]--;
        if(m[i+2]==0) m.erase(i+2);
        if(findsequence(m)==true) return true;
        for(i=i+3;m.find(i)!=m.end();i++)
        {
            m[i]--;
            if(m[i]==0) m.erase(i);
            if(findsequence(m)==true) return true;
        }
        return false;
    }
    bool isPossible(vector<int>& nums) {
        map<int,int> m;
        for(auto iter=nums.begin();iter!=nums.end();iter++)
        {
            if(m.find(*iter)!=m.end()) m[*iter]++;
            else m.insert(pair<int,int>(*iter,1));
        }
        return findsequence(m);
    }
};