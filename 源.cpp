#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        //1977-1-1 was Saturday.
        vector<int>month_sum(13);
        int year_sum = 0;
        for (int i = 1; i <= 7; i += 2)month_sum[i] = 31;
        for (int i = 8; i <= 12; i += 2)month_sum[i] = 31;
        for (int i = 4; i <= 6; i += 2)month_sum[i] = 30;
        for (int i = 9; i <= 11; i += 2)month_sum[i] = 30;
        if (isLeapyear(year)) month_sum[2] = 29;
        else  month_sum[2] = 28;
        int sum = 0;//from 1977-1-1
        for (int i = 1977; i < year ; i++)
            if (isLeapyear(i))sum += 366;
            else sum += 365;
        for (int i = 1; i < month; i++)sum += month_sum[i];
        sum += day - 1;
        sum = sum % 7;
        if (sum == 0)return "Saturday";
        else if (sum == 1)return "Sunday";
        else if (sum == 2)return "Monday"; 
        else if (sum == 3)return "Tuesday";
        else if (sum == 4)return "Wednesday";
        else if (sum == 5)return "Thursday";
        else return "Friday";        
    return "";
    }
    bool isLeapyear(int year) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)return true;
        else return false;
    }
};
int main() {
    Solution sol;
    cout<<sol.dayOfTheWeek(18, 8, 2020);
    return 0;
}
