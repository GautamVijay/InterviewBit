/* 
Number of Digit One
-------------------
Given an integer A, find and return the total number of digit 1 
appearing in all non-negative integers less than or equal to A. 

Input Format
The only argument given is the integer A.

Output Format
Return the total number of digit 1 appearing in all non-negative integers less than or equal to A.

Constraints
0 <= A <= 10^9

For Example
Input 1:
    A = 10
Output 1:
    2

Input 2:
    A = 20
Output 2:
    12

 */

int Solution::solve(int A)
{
    // BruteForce Method
    // int ans = 0;
    // for(int i = 0; i <= A; i++){
    //     string s = to_string(i);
    //     ans = ans + count(s.begin(), s.end(), '1');
    // }
    // return ans;

    // Complexity O(nlogn)

    int ans = 0;
    for (int i = 1; i <= A; i = i * 10)
    {
        int divider = i * 10;
        ans = ans + (A / divider) * i + min(max(A % divider - i + 1, 0), i);
    }

    return ans;
}


/* 
Explanation :
https://leetcode.com/articles/number-of-digit-one/

 */