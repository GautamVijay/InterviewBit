/* 
Sub-matrix Sum Queries
----------------------

Given a matrix of integers A of size N x M and multiple queries Q, 
for each query find and return the submatrix sum. 
Inputs to queries are top left (b, c) and bottom right (d, e) indexes of submatrix 
whose sum is to find out. 

Note: Rows are numbered from top to bottom and columns are numbered from left to right. 
Sum may be large so return the answer mod 10^9 + 7. 

Input Format
The first argument given is the integer matrix A.
The second argument given is the integer array B.
The third argument given is the integer array C.
The fourth argument given is the integer array D.
The fifth argument given is the integer array E.
(B[i], C[i]) represents the top left corner of the i'th query.
(D[i], E[i]) represents the bottom right corner of the i'th query.

Output Format
Return the submatrix sum (% 10^9 + 7) for each query in the form of an integer array.

Constraints
1 <= N, M <= 1000
-100000 <= A[i] <= 100000
1 <= Q <= 100000
1 <= B[i] <= D[i] <= N
1 <= C[i] <= E[i] <= M

For Example

Input 1:
    A = [   [1, 2, 3]
            [4, 5, 6]
            [7, 8, 9]   ]
    B = [1, 2]
    C = [1, 2]
    D = [2, 3]
    E = [2, 3]
Output 1:
    [12, 28]

Input 2:
    A = [   [5, 17, 100, 11]
            [0, 0,  2,   8]    ]
    B = [1, 1]
    C = [1, 4]
    D = [2, 2]
    E = [2, 4]
Output 2:
    [22, 19]
 */

vector<int> Solution::solve(vector<vector<int>> &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E)
{

    vector<int> ans;
    int N = A.size();    // number of rows
    int M = A[0].size(); // number of columns
    vector<vector<int>> temp(N + 1, vector<int>(M + 1, 0));
    long long int modder = 1000000007;

    // // fill first row with zeros
    // for(int i = 0; i <= M; i++){
    //     temp[0][i] = 0;
    // }

    // // fill first column with zeros
    // for(int i = 0; i <=N; i++){
    //     temp[i][0] = 0;
    // }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            temp[i][j] = (modder + temp[i - 1][j] % modder + temp[i][j - 1] % modder + A[i - 1][j - 1] % modder - temp[i - 1][j - 1] % modder) % modder;
        }
    }

    for (auto a : temp)
    {
        for (auto b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << "-------------" << endl;

    for (int i = 0; i < B.size(); i++)
    {
        int w = B[i];
        int x = C[i];
        int y = D[i];
        int z = E[i];

        int res = (modder + temp[y][z] % modder - temp[w - 1][z] % modder - temp[y][x - 1] % modder + temp[w - 1][x - 1] % modder) % modder;
        if (res < 0)
        {
            res = res + modder;
        }

        ans.push_back(res % modder);
        cout << res << endl;
        cout << "-------------" << endl;
    }

    return ans;
}