/* 
Repeat and Missing Number Array
You are given a read only array of n integers from 1 to n. Each integer appears exactly once except A which appears twice and B which is missing. Return A and B. Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? Note that in your output A should precede B. Example:
Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4
 */

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int n = A.size();
    long long int sum = (n * (n+1) ) /2, squared_sum = (n * (n +1) *(2*n +1) )/6;
    long long int missing=0, repeated=0;
    
    for(int i=0;i<A.size(); i++){
       sum = sum - (long long int)A[i];
       squared_sum = squared_sum - (long long int)A[i]*(long long int)A[i];
    }
    
    missing = (sum + squared_sum/sum)/2;
    repeated= missing - sum;
    vector <int> result;
    result.push_back(repeated);
    result.push_back(missing);
    return result;
}