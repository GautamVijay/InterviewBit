
/* 
Count pairs in array whose sum is divisible by the given number
----------------------------------------------------------------

Given an array of integers A and an integer B, 
find and return the number of pairs in A whoes sum is divisible by B. 
Since the answer may be large, return the answer modulo (10^9 + 7). 

Input Format
The first argument given is the integer array A.
The second argument given is the integer B.

Output Format
Return the total number of pairs for which the sum is divisible by B modulo (10^9 + 7).

Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 10^9 
1 <= B <= 10^6

For Example

Input 1:
    A = [1, 2, 3, 4, 5]
    B = 2
Output 1:
    4

Input 2:
    A = [5, 17, 100, 11]
    B = 28
Output 2:
    1
 */


int Solution::solve(vector<int> &A, int B) {
    int mod = 1000000007;
    long long int n = A.size();

    long long int cnt[B];

    // filling zeros 
    for(int i=0; i<B; i++)
        cnt[i]=0;

    // cnt vector hold the count of the mods
    // input 1 : [2, 3]
    // since 2 values (2 and 4) are % B = 0 
    // 3 values (1, 3 and 5) are %B = 1
    for(int i = 0; i < n; i++){
        cnt[A[i]%B]++;
    }

    long long int ans=0;
    ans+=(cnt[0]*(cnt[0]-1))/2;
        for(int i=1; i<=B/2 && i!=B-i; i++){
            ans+=cnt[i]*cnt[B-i];
        }

    // Special case where B is even
    if(B%2==0)
        ans+=(cnt[B/2]*(cnt[B/2]-1))/2;
    return (ans)%mod;
}
