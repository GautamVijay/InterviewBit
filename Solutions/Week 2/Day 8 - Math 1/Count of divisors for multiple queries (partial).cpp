/* 
Count of divisors for multiple queries

Given an array of integers A, find and return the count of divisors of each element of the array. Note: Order of the resultant array should be same as the input array. 
Input Format
The only argument given is the integer array A.
Output Format
Return the count of divisors of each element of the array in the form of an array.
Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 10^6
For Example
Input 1:
    A = [2, 3, 4, 5]
Output 1:
    [2, 2, 3, 2]

Input 2:
    A = [10, 20]
Output 2:
    [4, 6]
 */

vector<int> Solution::solve(vector<int> &A) {
    vector <int> ans;
    int n = A.size();
    for(int i = 0; i < n ; i++)
    {
        int x = A[i];
        int count = 0;
        for(int j = 1; j <= sqrt(x); j++)
        {
            if(x%j == 0)
            {
                if(x/j == j)
                    count++;
                else
                    count += 2;
            }
        }
        ans.push_back(count);
    }
    return ans;
}