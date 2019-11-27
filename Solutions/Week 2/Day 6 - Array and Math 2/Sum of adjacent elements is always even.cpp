/* 

Sum of adjacent elements is always even
Given an array of integers A, find and return the minimum elements to be removed such that in the resulting array the sum of any two adjacent values is even. 
Input Format
The only argument given is the integer array A.
Output Format
Return the minimum number of elements to be removed.
Constraints
1 <= length of the array <= 100000
-10^9 <= A[i] <= 10^9 
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
Output 1:
    2

Input 2:
    A = [5, 17, 100, 11]
Output 2:
    1

 */


int Solution::solve(vector<int> &A) {
    int odd = 0;
    int n = A.size();
    for(int i = 0; i < n; i++)
    {
        if(A[i] % 2)
            odd++;
    }
    return min(odd, n-odd);
}