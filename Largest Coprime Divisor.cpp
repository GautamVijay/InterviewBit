/*

Largest Coprime Divisor
You are given two positive numbers A and B. You need to find the maximum valued integer X such that:
X divides A i.e. A % X = 0
X and B are co-prime i.e. gcd(X, B) = 1
For example,
A = 30
B = 12
We return
X = 5

*/



int gcd (int x, int y){
    if (x == y)
        return x;
    if(x == 0 || y == 0)
        return 0;
    if(x > y)
        return gcd(x-y, y);
    else
        return gcd(x, y-x);
}

int Solution::cpFact(int A, int B) {
    while(gcd(A,B) != 1){
        A = A / gcd(A,B);
    }
    return A;
}