/* 
First Missing Integer
Given an unsorted integer array, find the first missing positive integer. 
Example: Given [1,2,0] return 3, [3,4,-1,1] return 2, [-8, -7, -6] returns 1 
Your algorithm should run in O(n) time and use constant space.
 */

int Solution::firstMissingPositive(vector<int> &A) {
    
    int n = A.size();
    int i = 0, j = 0;
    
    // shift allnegative numbers to the left of the vector.
    for(i = 0; i< n; i++)
    {
        if(A[i]<=0)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            j++;
        }
    }
    
    // j holds the position of the positive points starts.
    for(i = j; i < n; i++)
    {
        if(abs(A[i])+j-1 < n && abs(A[i])+j-1 >= 0)
        {
            if(A[abs(A[i])+j-1]>0)
                A[abs(A[i])+j-1] = -A[abs(A[i])+j-1];
        }
    }
    
    for(int i = j; i < n; i++)
    {
        if(A[i]>0)
            return (i-j+1);
    }
    
    return (n-j+1);
    
    
}