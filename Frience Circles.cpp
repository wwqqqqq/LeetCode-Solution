
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int count=0;
        int result=0;
        int student[200];
        int num=M.size();
        int i,j;
        for(i=0;i<num;i++) student[i]=-1;
        for(i=0;i<num;i++)
        {
            for(j=i+1;j<num;j++)
            {
                if(M[i][j]==1)
                {
                    if(student[i]==-1&&student[j]==-1)
                    {
                        count++;
                        result++;
                        student[i]=count;
                        student[j]=count;
                    }
                    else if(student[i]==-1&&student[j]!=-1)
                    {
                        student[i]=student[j];
                    }
                    else if(student[i]!=-1&&student[j]==-1)
                    {
                        student[j]=student[i];
                    }
                    else
                    {
                        if(student[i]!=student[j])
                        {
                            result--;
                            int temp=student[j];
                            for(int k=0;k<num;k++)
                                if(student[k]==temp) student[k]=student[i];
                        }
                    }
                }
            }
        }
        for(i=0;i<num;i++)
            if(student[i]==-1) result++;
        return result;
    }
};