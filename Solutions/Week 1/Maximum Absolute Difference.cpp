/* 

Maximum Absolute Difference
---------------------------
You are given an array of N integers, A1, A2 ,..., AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N. f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x. For example,
A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.


 */



int Solution::maxArr(vector<int> &A) {
    
    // int max = 0;
    int n = A.size();
    // for(int i = 0; i < n; i++ )
    //     {
    //         for(int j = 0; j < n; j++)
    //         {
    //             if((abs(A[i]-A[j]) + abs(i-j))> max)
    //                 max = abs(A[i]-A[j]) + abs(i-j);
    //                 // cout << (abs(A[i]-A[j]) + abs(i-j)) << " ";
    //         }
    //         // cout << "**";
    //     }
        
    // return max;
    
    int min1 = INT_MAX;
    int max1 = INT_MIN;
    int min2 = INT_MAX;
    int max2 = INT_MIN;
    
    int res = INT_MIN;
    
    for(int i =0; i < n; i++)
    {
        max1=max(max1,A[i]+i);
        min1=min(min1,A[i]+i);
        max2=max(max2,A[i]-i);
        min2=min(min2,A[i]-i);
    }
    for(int i=0;i<n;i++)
    {
        res=max(res,abs(max1-(A[i]+i)));
        res=max(res,abs(min1-(A[i]+i)));
        res=max(res,abs(max2-(A[i]-i)));
        res=max(res,abs(min2-(A[i]-i)));
    }
    return res;
}