class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        map<int,int> result;
        for(auto iter1=buildings.begin();iter1<buildings.end();iter1++)
        {
            int left=(*iter1)[0];
            int right=(*iter1)[1];
            int height=(*iter1)[2];
            if(result.size()==0)
            {
                result.insert(pair<int,int>(left,height));
                result.insert(pair<int,int>(right,0));
                continue;
            }
            auto p1=result.end();
            auto p2=result.end();
            pair<int,int> temp1,temp2;
            temp1.second=0;
            auto iter2=result.begin();
            for(iter2=result.begin();iter2!=result.end();iter2++)
            {
                if(p1==result.end()&&iter2->first<left) temp1=*iter2;
                if(p1==result.end()&&iter2->first>=left) p1=iter2;
                if(p2==result.end()&&iter2->first<=right) temp2=*iter2;
                if(p2==result.end()&&iter2->first>=right) p2=iter2;
                if(p1!=result.end()&&p2!=result.end()) break;
            }
            if(p1==result.end())
            {
                result.insert(pair<int,int>(left,height));
                result.insert(pair<int,int>(right,0));
                continue;
            }
            int height2=(p2==result.end()||(p2==result.begin()&&p2->first<right))?0:temp2.second;
            int last;
            if(p1->first==left&&p1->second<height)
            {
                if(temp1.second!=height) 
                {
                    result[left]=height;
                }
                else result.erase(left);
                last=height;
            }
            else if(p1->first>left && temp1.second<height)
            {
                result.insert(pair<int,int>(left,height));
                last=height;
            }
            else if(p1->first==left) last=p1->second;
            else last=temp1.second;
            for(iter2=result.begin();iter2!=result.end()&&iter2->first<right;iter2++)
            {
                if(iter2->first<=left) continue;
                if(iter2->second<=height)
                {
                    if(last==height) 
                    {
                        iter2=result.erase(iter2); iter2--;
                    }
                    else
                    {
                        iter2->second=height;
                        last=height;
                    }
                }
                else last=iter2->second;
            }
            if(iter2==result.end()) result.insert(pair<int,int>(right,0));
            else if(iter2->first>right && height2<height)
                result.insert(pair<int,int>(right,height2));


        }
        //return result;
        vector<pair<int,int>> res;
        for(auto iter=result.begin();iter!=result.end();iter++)
            res.push_back(*iter);
        return res;
    }
};