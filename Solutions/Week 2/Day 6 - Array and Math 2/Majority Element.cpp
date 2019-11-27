/* 
Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times. You may assume that the array is non-empty and the majority element always exist in the array. Example :
Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2.
 */

int Solution::majorityElement(const vector<int> &A) {
    // Moore's Voting algorithm
    int major_ind = 0, count = 1;
    for(int i = 0; i < A.size(); i++)
    {
        if(A[major_ind] == A[i])
            count++;
        else
        {
            count--;
            if(count==0)
            {
                major_ind = i;
                count = 1;
            }
        }
    }
    
    return A[major_ind];
}