class Solution {
public:
    bool function(vector<vector<int>>::iterator beg,vector<vector<int>>::iterator ed, int i, set<int>&s1, set<int>&s2)
    {
        if(beg==ed) return true;
        if(s2.find(i)!=s2.end()) return false;
        vector<int> temp=*beg;
    
        vector<int> temp2;
        bool insert_i=false;
        for(auto iter=temp.begin();iter!=temp.end();iter++)
            if(s1.find(*iter)!=s1.end()) return false;
        for(auto iter=temp.begin();iter!=temp.end();iter++)
            if(s2.find(*iter)==s2.end())
            {
                s2.insert(*iter);
                temp2.push_back(*iter);
            }
        if(s1.find(i)==s1.end())
        {
            s1.insert(i);
            insert_i=true;
        }
        if(function(beg+1,ed,i+1,s1,s2)==true) return true;
        if(beg+1<ed && (*(beg+1)).size()>0 && function(beg+1,ed,i+1,s2,s1)==true) return true;
        for(auto iter=temp2.begin();iter<temp2.end();iter++)
            s2.erase(*iter);
        if(insert_i==true) s1.erase(i);
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        set<int> s1,s2;
        int i,j;
        if(graph.size()==0) return true;
        return function(graph.begin(),graph.end(),0,s1,s2);
    }
};