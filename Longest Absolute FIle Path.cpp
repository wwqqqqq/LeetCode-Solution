class Solution {
public:
    int getIndent(string input) {
        int count = 0;
        for(int i = 0; i < input.size(); i++) {
            if(input[i] != '\t')
                break;
            count++;
        }
        return count;
    }
    bool isfile(string input) {
        if(input.size() == 0)
            return false;
        if(input.find('.') == input.npos)
            return false;
        return true;
    }
    int lengthLongestPath(string input) {
        vector<string> name;
        int max = 0;
        int count = 0;
        while(input.size() > 0) {
            int nl = input.find('\n');
            int indent;
            string temp;
            if(nl == input.npos) {
                indent = getIndent(input);
                temp = input;
                input = "";
            }
            else {
                temp = input.substr(0, nl);
                input = input.substr(nl+1);
                indent = getIndent(temp);
            }

            while(name.size() >= indent + 1) {
                string t1 = name[name.size()-1];
                count = count - t1.size();
                name.erase(name.end()-1);
            }
            temp.erase(temp.begin(),temp.begin()+indent);
            if(isfile(temp)) {
                count += temp.size();
                if(count > max)
                    max = count;
            }
            else {
                temp.append("/");
                count += temp.size();
            }
            name.push_back(temp);
        }
        return max;
    }
};