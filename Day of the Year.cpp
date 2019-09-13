class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));
        /*
        if (year is not divisible by 4) then (it is a common year)
        else if (year is not divisible by 100) then (it is a leap year)
        else if (year is not divisible by 400) then (it is a common year)
        else (it is a leap year)
        */
        bool leapyear = false;
        if(year % 4 == 0 && (year % 400 == 0 || year % 100 != 0))
            leapyear = true;
        /*
        if(year % 4 != 0) leapyear = false;
        else if(year % 100 != 0) leapyear = true;
        else if(year % 400 != 0) leapyear = false;
        else leapyear = true;
        */
        // months that have 31 days: 1, 3, 5, 7, 8, 10, 12
        // months that have 30 days: 4, 6, 9, 11
        // February: 28 days in common years but 29 days in leap years
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(leapyear)
            days[1] = 29;
        int acc = 0;
        for(int i = 1; i < month; i++) {
            acc += days[i-1];
        }
        acc += day;
        return acc;
    }
};