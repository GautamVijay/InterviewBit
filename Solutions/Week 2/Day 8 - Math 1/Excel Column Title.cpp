/* 
Excel Column Title
Given a positive integer, return its corresponding column title as appear in an Excel sheet. For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
 */


string Solution::convertToTitle(int A) {

    vector <char> ans;
    
    while(A>0)
    {
        int remainder = A % 26;
        if(remainder == 0)
        {
            ans.push_back('Z');
            A = (A/26)-1;
        }
        else
        {
            ans.push_back((remainder-1) + 'A');
            A = A/26;
        }
    }
    
    reverse(ans.begin(), ans.end());
    
    // answer needed in string
    string str(ans.begin(), ans.end());
    return str;
}