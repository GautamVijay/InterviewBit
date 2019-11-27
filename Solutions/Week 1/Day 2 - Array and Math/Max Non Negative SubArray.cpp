/* 
Max Non Negative SubArray
--------------------------
Given an array of integers, A of length N, find out the maximum sum sub-array of non negative numbers from A. The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid. Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Find and return the required subarray. NOTE:
    1. If there is a tie, then compare with segment's length and return segment which has maximum length.
    2. If there is still a tie, then return the segment with minimum starting index.

 Input Format:
The first and the only argument of input contains an integer array A, of length N.
Output Format:
Return an array of integers, that is a subarray of A that satisfies the given conditions.
Constraints:
1 <= N <= 1e5
1 <= A[i] <= 1e5
Examples:
Input 1:
    A = [1, 2, 5, -7, 2, 3]

Output 1:
    [1, 2, 5]

Explanation 1:
    The two sub-arrays are [1, 2, 5] [2, 3].
    The answer is [1, 2, 5] as its sum is larger than [2, 3].

Input 2:
    A = [10, -1, 2, 3, -4, 100]

Output 2:
    [100]

Explanation 2:
    The three sub-arrays are [10], [2, 3], [100].
    The answer is [100] as its sum is larger than the other two.
 */


vector<int> Solution::maxset(vector<int> &A) {
    // vector <int> result;
    // int n = A.size();
    // long long cursum = 0, curstart = 0, curlength = 0;
    // long long maxsum = 0, maxstart = 0, maxlength = 0;
    
    // for(int i = 0; i < n; i++)
    // {
    //     // cout << "i == " << i << endl;
    //     if(A[i]>=0)
    //     {
    //         cursum = cursum + A[i];
    //         curlength++;
    //         // cout << "cursum "<<cursum << " " << curlength << endl;
    //     }
        
    //     else
    //     {
    //         if((cursum >= maxsum && curlength > maxlength)||(cursum > maxsum && curlength >= maxlength))
    //         {
    //             maxsum = cursum;
    //             maxstart = curstart;
    //             maxlength = curlength;
    //             // cout << "maxsum "<< maxsum << " " << maxlength << endl;
    //         }
    //         curstart = i +1;
    //         cursum = 0;
    //         curlength = 0;
    //     }
    // }
    
    // if((cursum >= maxsum && curlength > maxlength)||(cursum > maxsum && curlength >= maxlength))
    // {
    //     maxsum = cursum;
    //     maxlength = curlength;
    //     maxstart = curstart;
    // }
    // // for(int j = maxstart; j < maxstart+maxlength; j++)
    // // {
        
    // // }
    // copy(A.begin()+maxstart, A.begin()+maxstart+maxlength, back_inserter(result));
    // // cout << result.size();
    // // for(auto a : result)
    // //     cout << a << " ";
    // // cout << endl;
    // // if(result.size() == 0)
    // // {
    // //     vector<int> a;
    // //     a.push_back(A[0]);
    // //     return a;
    // // }
    // return result;
    int N = A.size();

    long long mx_sum = 0;
    long long cur_sum = 0;
    int mx_range_left = -1;
    int mx_range_right = -1;
    int cur_range_left = 0;
    int cur_range_right = 0;

    while(cur_range_right < N) {
        if(A[cur_range_right] < 0) {
            cur_range_left = cur_range_right + 1;
            cur_sum = 0;
        } else {
            cur_sum += (long long)A[cur_range_right];
            if(cur_sum > mx_sum) {
                mx_sum = cur_sum;
                mx_range_left = cur_range_left;
                mx_range_right = cur_range_right + 1;
            } else if(cur_sum == mx_sum) {
                if(cur_range_right + 1 - cur_range_left > mx_range_right - mx_range_left) {
                    mx_range_left = cur_range_left;
                    mx_range_right = cur_range_right + 1;
                }
            }
        }
        cur_range_right++;
    }
    vector<int> ans;
    if(mx_range_left == -1 || mx_range_right == -1)
            return ans;

    for(int i = mx_range_left; i < mx_range_right; ++i)
            ans.push_back(A[i]);
    return ans;
}