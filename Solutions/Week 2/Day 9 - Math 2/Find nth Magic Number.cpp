/* 

Find nth Magic Number
Given an integer A, find and return the A'th magic number.
 A magic number is defined as a number which can be 
 expressed as a power of 5 or sum of unique powers of 5. 
 First few magic numbers are 5, 25, 30(5 + 25), 125, 130(125 + 5), …. 

Input Format
The only argument given is integer A.

Output Format
Return the A'th magic number.

Constraints
1 <= A <= 5000

For Example
Input 1:
    A = 10
Output 1:
    650

Input 2:
    A = 3
Output 2:
    30
 */


int Solution::solve(int A) {
    
    int pow = 1;
    int ans = 0;
    
    while(A){
        pow = pow *5;
        if(A&1)
            ans += pow;
        A>>=1;
    }
    return ans;
}