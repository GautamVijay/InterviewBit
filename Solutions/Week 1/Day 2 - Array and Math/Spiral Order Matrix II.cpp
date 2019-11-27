/* 
Spiral Order Matrix II
-----------------------
Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order. 
 Input Format:
The first and the only argument contains an integer, A.
Output Format:
Return a 2-d matrix of size A x A satisfying the spiral order.
Constraints:
1 <= A <= 1000
Examples:
Input 1:
    A = 3

Output 1:
    [   [ 1, 2, 3 ],
        [ 8, 9, 4 ],
        [ 7, 6, 5 ]   ]

Input 2:
    4

Output 2:
    [   [1, 2, 3, 4],
        [12, 13, 14, 5],
        [11, 16, 15, 6],
        [10, 9, 8, 7]   ]
 */


vector<vector<int> > Solution::generateMatrix(int A) {
    int n = A;
    int top = 0;
    int bottom = n-1;
    int left = 0;
    int right = n-1;
    int direction = 0; // 0-right, 1-down, 2-left, 3-up
    int count = 1;
    vector <vector<int>> result(n, vector<int>(n));
    while(top <= bottom && left <= right)
    {
        if(direction == 0) // moving left to right
        {
            for(int i = left; i <= right; i++)
            {
                result[top][i] = count;
                count++;
            }
            direction = 1;
            top++;
        }
        
        else if(direction == 1) // moving top to bottom
        {
            for(int i = top; i <= bottom; i++)
            {
                result[i][right] = count;
                count++;
            }
            direction = 2;
            right--;
        }
        
        else if(direction == 2) // moving right to left
        {
            for(int i = right; i >= left; i--)
            {
                result[bottom][i] = count;
                count++;
            }
            direction = 3;
            bottom--;
        }
        else if(direction == 3) // moving down to up
        {
            for(int i = bottom; i >= top; i--)
            {
                result[i][left] = count;
                count++;
            }
            direction = 0;
            left++;
        }
    }
    
    return result;
    
}