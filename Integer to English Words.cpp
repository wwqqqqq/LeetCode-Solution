class Solution {
public:
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        string d1[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string d2[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string d3[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string quant[] = {"", "Thousand", "Million", "Billion"};
        vector<int> vec;
        while(num != 0) {
            vec.push_back(num % 10);
            num /= 10;
        }
        
        string result;
        bool used3 = false;
        bool notzero = false;
        for(int i = vec.size() - 1; i >= 0; i--) {
            if(result.size() != 0 && result[result.size() - 1] != ' ')
                result.append(" ");
            
            if(vec[i] != 0)
                notzero = true;
            
            if(i % 3 == 1) {
                result.append(d2[vec[i]]);
                if(vec[i] == 1)
                    used3 = true;
            }
            else if(i % 3 == 0 && used3 == true) {
                result.append(d3[vec[i]]);
                used3 = false;
            }
            else
                result.append(d1[vec[i]]);
            
            if(i % 3 == 0 && notzero == true) {
                if(result.size() != 0 && result[result.size() - 1] != ' ' && i != 0)
                    result.append(" ");
                result.append(quant[i / 3]);
                notzero = false;
            }
            if(i % 3 == 2 && vec[i] != 0)
                result.append(" Hundred");
        }
        if(result[result.size() - 1] == ' ')
            result.erase(result.size() - 1);
        
        return result;
    }
};