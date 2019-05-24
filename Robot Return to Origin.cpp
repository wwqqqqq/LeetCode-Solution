class Solution {
public:
    bool judgeCircle(string moves) {
        int count_u = 0, count_d = 0, count_l = 0, count_r = 0;
        for(int i = 0; i < moves.size(); i++) {
            switch(moves[i]) {
                case 'U': count_u++;
                    break;
                case 'D': count_d++;
                    break;
                case 'L': count_l++;
                    break;
                case 'R': count_r++;
                    break;
                default: break;
            }
        }
        if(count_u == count_d && count_l == count_r)
            return true;
        return false;
    }
};