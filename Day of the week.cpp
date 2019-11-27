/*
Day of the week
------------------
Given three integers A, B and C,
find and return the day of the week for the given date A/B/C where A represents the date, B represents the month and
C represents the year. Assume that Jan 1st 1 AD is a Monday in Gregorian calendar. February has 28 days(excluding leap years when it has 29 days). Leap
year is a year that is either (divisible by 400) or (divisible by 4 and not divisible by 100).

*/


string Solution::solve(int A, int B, int C) {

    // Following is a simple function suggested by Sakamoto, Lachman, Keith and Craver to calculate day. 
    // The following function returns 0 for Sunday, 1 for Monday, etc.
    int x[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    C -= B < 3;
    int d = (C + C/4 - C/100 + C/400 + x[B-1] + A) % 7;
    
    // sunday, monday, tuesday, wednesday, thursday, friday, saturday
    map <int, string> day;
    day[0] = "sunday";
    day[1] = "monday";
    day[2] = "tuesday";
    day[3] = "wednesday";
    day[4] = "thursday";
    day[5] = "friday";
    day[6] = "saturday";
    
    return day[d];
}