/* 
Sorted Permutation Rank
-----------------------
Given a string, find the rank of the string amongst its permutations sorted lexicographically. 
Assume that no characters are repeated. 

Example :
Input : 'acb'
Output : 2

The order permutations with letters 'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba
The answer might not fit in an integer, so return your answer % 1000003

 */


int mod = 1000003;

// utility to find factorial
int factorial(int n){
    if(n==0) return 1;
    else
        return (n*factorial(n-1))%mod;
}

int Solution::findRank(string A) {
    int ans = 0;
    int n = A.length();
    
    for(int i = 0; i < n-1; i++)
    {
        int cnt = 0;
        // how many smaller char from i
        for(int j = i+1; j < n; j++)
        {
            if(A[j]<A[i])
                cnt++;
        }
        
        ans = ans + (cnt*factorial(n-i-1))%mod;
    }
    
    return (ans+1)%mod;
}