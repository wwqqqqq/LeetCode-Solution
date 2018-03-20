class Solution {
public:
    int maxArea(vector<int>& height) {/*
        vector<int>::iterator iter1,iter2;
        if(height.size()<2)
            return 0;
        int maxarea=0;
        for(iter1=height.begin();iter1!=height.end();iter1++)
            for(iter2=iter1;iter2!=height.end();iter2++)
            {
                int area = (iter2-iter1)*((*iter1<*iter2)?*iter1:*iter2);
                if(area>maxarea) maxarea=area;
            }
        return maxarea;*/
        if(height.size()<2) return 0;
        int maxarea=0;
        vector<int>::iterator iter1,iter2;
        for(iter1=height.begin();iter1!=height.end();iter1++)
        {
            int h=*iter1;
            for(iter2=height.begin();iter2<iter1;iter2++)
                if(*iter2>=h)
                    break;
            if(*iter2>=h)
            {
                int area = (iter1-iter2)*h;
                if(area>maxarea) maxarea=area;
            }
            int width=iter1-iter2;
            for(iter2=height.end()-1;iter2>iter1+width;iter2--)
                if(*iter2>=h)
                    break;
            if(*iter2>=h)
            {
                int area = (iter2-iter1)*h;
                if(area>maxarea) maxarea=area;
            }
        }
        return maxarea;
    }
};