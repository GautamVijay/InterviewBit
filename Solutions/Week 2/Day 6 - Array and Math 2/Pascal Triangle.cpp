/* 
Pascal Triangle
Given numRows, generate the first numRows of Pascal's triangle. Pascal's triangle : To generate A[C] in row R, sum up A'[C] and A'[C-1] from previous row R - 1. Example: Given numRows = 5, Return
[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
] 
*/


vector<vector<int> > Solution::solve(int A) {

    vector<vector<int>> res;
    if(A==0)
        return res;
    vector<int> v;
    v.push_back(1);
    res.push_back(v);
    
    for(int i = 1; i < A; i++)
    {
        vector <int> v;
        v.push_back(1);
        for(int j = 1; j < i; j++)
        {
            v.push_back(res[i-1][j]+res[i-1][j-1]);
        }
        v.push_back(1);
        res.push_back(v);
    }
    return res;
}