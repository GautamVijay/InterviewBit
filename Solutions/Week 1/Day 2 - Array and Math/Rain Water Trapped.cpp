/* 
Rain Water Trapped
-------------------
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining. 
Input Format
The only argument given is integer array A.
Output Format
Return the total water it is able to trap after raining..
For Example
Input 1:
    A = [0,1,0,2,1,0,1,3,2,1,2,1]
Output 1:
    6

 */



int Solution::trap(const vector<int> &A) {
    int count_value = 0;
    
    int n =  A.size();
    
    int left = 0;
    int right = 0;
    int left_mark = 0, right_mark = n-1; 
      
    while(left_mark <= right_mark)  
    { 
        if(A[left_mark] < A[right_mark]) 
        { 
            if(A[left_mark] > left) 
            left = A[left_mark]; 
            else
            count_value += left - A[left_mark]; 
            left_mark++; 
        } 
        else
        { 
            if(A[right_mark] > right) 
            right = A[right_mark]; 
            else
            count_value += right - A[right_mark]; 
            right_mark--; 
        } 
    } 
      
    
    
    return count_value;
}