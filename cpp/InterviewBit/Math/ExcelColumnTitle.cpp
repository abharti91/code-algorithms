//############### AMAZON
/*
Excel Column Title
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
*/

string Solution::convertToTitle(int A) {

    string ans = "";
    char c[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    while(A != 0){
        ans += c[(A-1) % 26];
        A = (A-1) / 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
