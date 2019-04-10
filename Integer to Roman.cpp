class Solution {
public:
    string intToRoman(int num) {
        int d1 = num % 10;
        int d2 = (num / 10) % 10;
        int d3 = (num / 100) % 10;
        int d4 = (num / 1000) % 10;
        string s;
        
        s.append(d4, 'M');
        
        if(d3 == 9)
            s.append("CM");
        else if(d3 >= 5) {
            s.append("D");
            s.append(d3 - 5, 'C');
        }
        else if(d3 == 4) {
            s.append("CD");
        }
        else s.append(d3, 'C');
        
        if(d2 == 9)
            s.append("XC");
        else if(d2 >= 5) {
            s.append("L");
            s.append(d2 - 5, 'X');
        }
        else if(d2 == 4)
            s.append("XL");
        else s.append(d2, 'X');
        
        if(d1 == 9)
            s.append("IX");
        else if(d1 >= 5) {
            s.append("V");
            s.append(d1 - 5, 'I');
        }
        else if(d1 == 4)
            s.append("IV");
        else s.append(d1, 'I');
        
        return s;
    }
};