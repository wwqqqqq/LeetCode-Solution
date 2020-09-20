class Solution
{
public:
    vector<string> strSplit(string text)
    {
        // split the string by space
        vector<string> result;
        int start = 0;
        bool isWord = false;
        for (int i = 0; i < text.size(); i++)
        {
            if (text[i] == ' ')
            {
                if (isWord)
                {
                    isWord = false;
                    result.push_back(text.substr(start, i - start));
                }
            }
            else
            {
                if (!isWord)
                {
                    isWord = true;
                    start = i;
                }
            }
        }
        if (isWord)
        {
            result.push_back(text.substr(start));
        }
        return result;
    }
    string reorderSpaces(string text)
    {
        int count = 0;
        for (int i = 0; i < text.size(); i++)
        {
            if (text[i] == ' ')
                count++;
        }
        vector<string> words = strSplit(text);
        int numWords = words.size();
        int numSpace = (numWords == 1) ? 0 : (count / (numWords - 1));
        int extraSpace = count - numSpace * (numWords - 1);
        string result;
        for (int i = 0; i < words.size(); i++)
        {
            result = result + words[i];
            if (i < words.size() - 1)
            {
                result.append(numSpace, ' ');
            }
            else
            {
                result.append(extraSpace, ' ');
            }
        }
        return result;
    }
};