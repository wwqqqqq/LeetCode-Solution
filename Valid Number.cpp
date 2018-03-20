class Solution {
public:
    bool isNumber(string s) {
        int i;
        int size=s.size();
        bool is_float=false;
        bool have_e=false;
        bool end=false;
        bool have_n=false;
        char c='\0';
        char last_c=' ';
        i=0;
        while(s[i]==' ') i++;
        for(;i<size;i++)
        {
            c = s[i];
            if(c==' ') end=true;
            else if(end==true) return false;
            else if(c>='0'&&c<='9')
                have_n=true;
            else if(c=='-'||c=='+')
            {
                if(last_c!=' '&&last_c!='e') return false;
            }
            else if(c=='.')
            {
                if(is_float==true) return false;
                else if(have_e==true) return false;
                else is_float=true;
            }
            else if(c=='e')
            {
                if(have_n==false) return false;
                else if(have_e==true) return false;
                else have_e=true;
            }
            else return false;
            if(c!=' ') last_c=c;
        }
        if(last_c=='e'||last_c==' '||have_n==false||last_c=='-'||last_c=='+') return false;
        return true;
    }
};