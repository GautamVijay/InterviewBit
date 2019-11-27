/* 
Length of longest consecutive ones
Given a binary string A. It is allowed to do at most one swap between any 0 and 1. Find and return the length of the longest consecutive 1’s that can be achieved. 
Input Format
The only argument given is string A.
Output Format
Return the length of the longest consecutive 1’s that can be achieved.
Constraints
1 <= length of string <= 1000000
A contains only characters 0 and 1.
For Example
Input 1:
    A = "111000"
Output 1:
    3

Input 2:
    A = "111011101"
Output 2:
    7
 */



int Solution::solve(string A) {
    int n = A.size();
    vector <int> left(n,0);
    vector <int> right(n,0);
    
    int count = 0;
    int total = 0;
    for(int i = 0; i <= n-1; i++)
    {
        if(A[i] == '1')
        {
            count++;
            total++;
            left[i] = count;
        }
        else
        {
            count = 0;
        }
    }
    count = 0;
    for(int i = n-1; i >=0; i--)
    {
        if(A[i]=='1')
        {
            count++;
            right[i] = count;
        }
        else 
        {
            count = 0;
        }
    }
    if(total = n)
        return total;
    int max = 0;
    int max_ind = 0;
    
    for(int i = 0; i <= n-1; i++)
    {
        if(A[i] == '0')
        {
            int temp = 0;
            if(i<n-1)
            temp = left[i-1]+right[i+1];
            else
            temp = left[i-1];
            cout << "i : " << i << " " << "temp : " << temp << endl;
            if(temp > max)
            {
                max = temp;
                max_ind = i;
            }
        }
    }
    
    for(auto a : left)
        cout << a;
    cout << endl;
    for(auto a : right)
        cout << a;
    cout << endl;
    
    if(max+1 <= total)
    return max+1;
    else 
        return max;
}