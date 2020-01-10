/* 
    Reverse Bits
Reverse the bits of an 32 bit unsigned integer A. Input Format:
    First and only argument of input contains an integer A
Output Format:
    return a single unsigned integer denoting minimum xor value
Constraints:
0 <= A < 2^32
For Examples :
Example Input 1:
    A = 0
Example Output 1:
    0
Explanation 1:
        00000000000000000000000000000000  
=>      00000000000000000000000000000000
Example Input 2:
    A = 3
Example Output 2:
    3221225472
Explanation 2:
          00000000000000000000000000000011 
=>        11000000000000000000000000000000
Since java does not have unsigned int, use long

 */


unsigned int Solution::reverse(unsigned int A) {

    // https://www.geeksforgeeks.org/write-an-efficient-c-program-to-reverse-bits-of-a-number/
    // unsigned int  NO_OF_BITS = sizeof(A) * 8; 
    // unsigned int reverse_num = 0, i, temp; 
  
    // for (i = 0; i < NO_OF_BITS; i++) 
    // { 
    //     temp = (A & (1 << i)); 
    //     if(temp) 
    //         reverse_num |= (1 << ((NO_OF_BITS - 1) - i)); 
    // } 
   
    // return reverse_num;
    
    
    unsigned int count = sizeof(A) * 8 - 1; 
    unsigned int reverse_num = A; 
      
    A >>= 1;  
    while(A) 
    { 
       reverse_num <<= 1;        
       reverse_num |= A & 1; 
       A >>= 1; 
       count--; 
    } 
    reverse_num <<= count; 
    return reverse_num;
}