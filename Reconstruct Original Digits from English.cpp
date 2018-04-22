class Solution {
public:
    vector<string> nums={"zero","one","two","three","four","five","six","seven","eight","nine"};
    bool insert(vector<int>& result,int n,int times,int* m)
    {
        for(int i=0;i<times;i++) result.push_back(n);
        for(int i=0;i<nums[n].size();i++)
        {
            m[nums[n][i]-'a']-=times;
            //if(m[nums[n][i]]==0) m.erase(m[nums[n][i]]);
            if(m[nums[n][i]-'a']<0) return false;
        }
        return true;
    }
    string originalDigits(string s) {
        //g-8, u-4, w-2, x-6, z-0
        //map<char,int> m;
        int m[26];
        for(int i=0;i<26;i++) m[i]=0;
        vector<int> result;
        for(int i=0;i<s.size();i++)
        {
            //if(m.find(s[i])==m.end()) m.insert(pair<char,int>(s[i],1));
            //else m[s[i]]++;
            m[s[i]-'a']++;
        }
        if(m['g'-'a']>0)
        {
            int eights=m['g'-'a'];
            insert(result,8,eights,m);
        }
        if(m['u'-'a']>0)
        {
            int fours = m['u'-'a'];
            insert(result,4,fours,m);
        }
        if(m['w'-'a']>0)
        {
            int twos=m['w'-'a'];
            insert(result,2,twos,m);
        }
        if(m['x'-'a']>0)
        {
            int sixes=m['x'-'a'];
            insert(result,6,sixes,m);
        }
        if(m['z'-'a']>0)
        {
            int zeros=m['z'-'a'];
            insert(result,0,zeros,m);
        }
        //f-5, h-3, o-1, r-3, s-7, t-3
        if(m['f'-'a']>0)
        {
            int fives=m['f'-'a'];
            insert(result,5,fives,m);
        }
        if(m['h'-'a']>0)
        {
            int threes=m['h'-'a'];
            insert(result,3,threes,m);
        }
        if(m['o'-'a']>0)
        {
            int ones=m['o'-'a'];
            insert(result,1,ones,m);
        }
        if(m['s'-'a']>0)
        {
            int sevens=m['s'-'a'];
            insert(result,7,sevens,m);
        }
        //e-9, i-9, n-9
        if(m['e'-'a']>0)
        {
            int nines=m['e'-'a'];
            insert(result,9,nines,m);
        }
        
        sort(result.begin(),result.end());
        string str(result.size()+1,'\0');
        for(int i=0;i<result.size();i++)
            str[i]=result[i]+'0';
        return str;
    }
};