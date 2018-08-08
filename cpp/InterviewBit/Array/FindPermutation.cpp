/*
Find Permutation
Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation
 of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes

Length of given string s will always equal to n - 1
Your solution should run in linear time and space.
Example :

Input 1:

n = 3

s = ID

Return: [1, 3, 2]
*/
void print(vector<int> A, int n){
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
    cout << endl;
}

vector<int> Solution::findPerm(const string A, int B) {

    int n = B, t, j;
    if(n == 0)
        return {};

    if(n == 1)
        return {1};

    //asumme ans = [1,2,3,4,5....]
    vector<int> ans;
    for(int i=0; i<n; i++){
        ans.push_back(i+1);
    }

    //print(ans, n);

    for(int i=1; i<n; i++){
        //cout << A[i-1] << "::";
        if(A[i-1] == 'D'){
            //swap in pairs in backward direction untill we find 'I'
            j = i;
            while(j-1 >=0 && A[j-1] == 'D'){
                t = ans[j-1];
                ans[j-1] = ans[j];
                ans[j] = t;
                j--;
            }
        }
        //print(ans, n);
    }
    return ans;
}
