/*

Pretty print a json object using proper indentation.

Every inner brace should increase one indentation to the following lines.
Every close brace should decrease one indentation to the same line and the following lines.
The indents can be increased with an additional ‘\t’
Example 1:

Input : {A:"B",C:{D:"E",F:{G:"H",I:"J"}}}
Output :
{
    A:"B",
    C:
    {
        D:"E",
        F:
        {
            G:"H",
            I:"J"
        }
    }
}
Example 2:

Input : ["foo", {"bar":["baz",null,1.0,2]}]
Output :
[
    "foo",
    {
        "bar":
        [
            "baz",
            null,
            1.0,
            2
        ]
    }
]
[] and {} are only acceptable braces in this case.

Assume for this problem that space characters can be done away with.

Your solution should return a list of strings, where each entry corresponds to a single line. The strings should not have “\n” character in them.
*/

#include<bits/stdc++.h>
#include<string>
using namespace std;

vector<string> prettyJSON(string A) {

    int n = A.length();
    vector<string> result;

    //s_tab is previous line string that removing what added by previous string
    //generally previous string would be some tabs followed by actual content
    //s_tab = some sequence of tabs
    string s = "", s_tab = "";

    for(int i=0; i<n; i++){
        //continue if found space
        if(A[i] == ' ')
            continue;

        //if c = ',' then push current string to result
        //next string should be s_tab
        if(A[i] == ','){
            s += ',';
            result.push_back(s);
            s = s_tab;
            continue;
        }

        //if c = '{' or '[', add this char to s and push back to result
        //next line should increase indent by 1 '\t' over previous length
        else if(A[i] == '{' || A[i] == '['){

            //remove any spaces before '{' or '['
            int j = i-1;
            while(A[j] == ' '){
                j--;
            }

            //case C:{   here string to be added will be  =>>  C:
            //case "foo",{ here since we have already takedn care , case we do not add it here
            //case {{   or [[ , here  previous { or [ is already taken care, dont push it
             if(i > 0 && A[j] != ',' && A[j] != '{' && A[j] != '['){
                result.push_back(s);
                s = s_tab;
            }

            //case { OR [, both should in same string
            //add it new s will be s_tabb
            //add one next indent ('\t') for next string and this will be new s_tab
            s += A[i];
            result.push_back(s);
            s = s_tab;
            s += '\t';
            s_tab = s;
            continue;
        }

        //if c = '{' or '[', add this char to s and push back to result
        //next line should decrease indent by 1 '\t' over previous length
        else if(A[i] == '}' || A[i] == ']'){

            //if prev is ] or }
            if(A[i-1] == '}' || A[i-1] == ']'){
                s.pop_back();
                s_tab = s;
                s += A[i];

                //case }, or ], comma should be taken along weith closing bracket as string
                if(i+1 < n && A[i+1] == ','){
                    s += ',';
                    i++;
                }
                result.push_back(s);
                s = s_tab;
            }
            //if prev is other than ] or }, then that and prapare new string
            //s.pop_back() helps to remove 1 indent ('\t') from end of string
            else{
                result.push_back(s);
                s = s_tab;
                s.pop_back();
                s_tab = s;

                //case ], or },
                s += A[i];
                if(i+1 < n && A[i+1] == ','){
                    s += ',';
                    i++;
                }
                result.push_back(s);
                s = s_tab;
            }
            continue;
        }

        //if A[i] is not , } ] {  [
        else{
            s += A[i];
        }
    }
    return result;
}


int main(){
    string s;
    cin >> s;
    vector<string> ans = prettyJSON(s);
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}
