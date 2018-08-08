/*You are given a read only array of n integers from 1 to n.
Each integer appears exactly once except A which appears twice and B which is missing.
Return A and B.
Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
Note that in your output A should precede B.
Example:
Input:[3 1 2 5 3]

Output:[3, 4]
A = 3, B = 4

*/
vector<int> Solution::repeatedNumber(const vector<int> &A) {

    int n = A.size();
    int xor1, a = 0, b = 0;

    if(n == 0)
        return {};

    vector<int> v;

    xor1 = A[0];
    for(int i=1; i<n; i++)
        xor1 = xor1 ^ A[i];

    for(int i=1; i<=n; i++)
        xor1 = xor1 ^ i;

    //now xor = a ^ b
    //cout << "a^b:" << xor1 << endl;

    //rightmost bit in xor
    int rb = xor1 & ~(xor1-1);

    //cout << "rightmost bit:" << rb << endl;

    for(int i=0; i<n; i++){
        if(A[i] & rb){
            a = a ^ A[i];
            //cout << A[i] << "went to set 1" << endl;
        }

        else{
            b = b ^ A[i];
            //cout << A[i] << "went to set 2" << endl;
        }

    }

    for(int i=1; i<=n; i++){
        if(i & rb){
            a = a ^ i;
            //cout << i << "went to set 1" << endl;
        }

        else{
            b = b ^ i;
            //cout << i << "went to set 2" << endl;
        }

    }


    int counta = 0, countb = 0;
    //check which is repeating
    for(int i=0; i<n; i++){
        if(A[i] == a)
            counta++;
        else if(A[i] == b)
            countb++;
    }

    if(counta){
        v.push_back(a);
        v.push_back(b);
    }
    else{
        v.push_back(b);
        v.push_back(a);
    }

    return v;
}
