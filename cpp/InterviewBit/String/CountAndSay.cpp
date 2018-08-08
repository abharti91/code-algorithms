/*

The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.
*/

string Solution::countAndSay(int n) {

    if(n == 0)
        return "";

    if(n == 1)
        return "1";

    string s1 = "11", s2 = "";
    char prev = s1[0];

    int count = 1, x = 2;

    while(x < n){

        int i = 1;

        while(i < s1.length()){
            count = 1;

            while(i < s1.length() && prev == s1[i]){
                count++;
                i++;
            }


            s2 += to_string(count);
            s2 += s1[i-1];

            if(i < s1.length())
                prev = s1[i];

            i++;

            if(i == s1.length() &&s1[i-2] != s1[i-1] ){
                s2 += to_string(1);
                s2 += s1[i-1];
            }
        }


        s1 = s2;
        //cout << s1 << endl;
        s2 = "";
        prev = s1[0];
        x++;

    }
    return s1;

}
