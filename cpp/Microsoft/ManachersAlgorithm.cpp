//Longest Palindorme in String O(n) time + O(1) space

/*
Case 1: L[currentRightPosition] = L[currentLeftPosition] applies when:

i-left palindrome is completely contained in center palindrome
i-left palindrome is NOT a prefix of center palindrome
Both above conditions are satisfied when
L[currentLeftPosition] < centerRightPosition – currentRightPosition

Case 2: L[currentRightPosition] = L[currentLeftPosition] applies when:

i-left palindrome is prefix of center palindrome (means completely contained also)
center palindrome is suffix of input string
Above conditions are satisfied when
L[currentLeftPosition] = centerRightPosition – currentRightPosition (For 1st condition) AND
centerRightPosition = 2*N where N is input string length N (For 2nd condition).

Case 3: L[currentRightPosition] > = L[currentLeftPosition] applies when:

i-left palindrome is prefix of center palindrome (and so i-left palindrome is completely contained in center palindrome)
center palindrome is NOT suffix of input string
Above conditions are satisfied when
L[currentLeftPosition] = centerRightPosition – currentRightPosition (For 1st condition) AND
centerRightPosition < 2*N where N is input string length N (For 2nd condition).
In this case, there is a possibility of i-right palindrome expansion and so length of i-right palindrome is at least as long as length of i-left palindrome.

Case 4: L[currentRightPosition] > = centerRightPosition – currentRightPosition applies when:

i-left palindrome is NOT completely contained in center palindrome
Above condition is satisfied when
L[currentLeftPosition] > centerRightPosition – currentRightPosition
In this case, length of i-right palindrome is at least as long (centerRightPosition – currentRightPosition) and there is a possibility of i-right palindrome expansion.

*/


/*
terminologies
    d = maxLength(len of palindrme centred at i), i = centrePosition, low = centreLeftPosition, high = centreRightPosition
    try to pick next centrePosition
    loop through (from i+1 to n) currentRightPosition
    currentLeftPosition = 2* centerPosition – currentRightPosition (since, centerPosition – currentLeftPosition = currentRightPosition – centerPosition)
    int centrePosition = i;
    int centreLeftPosition = low;
    int centreRightPosition = high;
*/


#include<bits/stdc++.h>
#include<string>
using namespace std;


//assuming s.length() is odd and outputs only odd length palindromes
string longestPalindromeSubstring(string s){
    int len = s.length();

    //to handle odd and even strings both, positions count
    //odd positions contains chars while even positions contains nothing
    //new string of length 2*len+1 is |a|b|c|b|e|f|g|h|,  assuming s = abcbefgh
    len = 2*len+1;

    int maxLength = 1, start = 0;
    int LPS[s.length()];
    std::fill_n(LPS, s.length(), 0);
    LPS[0] = 0;//represent extra space/bar
    LPS[1] = 1;//represent actual char
    int centrePosition;
    int currentRightPosition;

    for(centrePosition = 1; centrePosition < len; centrePosition++){
        bool expand = false;

        int centreLeftPosition = centrePosition-1, centreRightPosition = centrePosition+1;
        //if comparing indices are odd -> compare chars and maxLength is increased if they matched
        //if comparing indices are even -> dont compare and maxLength is unchanged
        //new index x is same as index x/2 in string s
        while(centreLeftPosition >= 0 && centreRightPosition < len &&
                        (s[centreLeftPosition/2] == s[centreRightPosition/2] && centreLeftPosition%2 != 0 && centreRightPosition%2 != 0) ||
                        (centreLeftPosition%2 == 0 && centreRightPosition%2 == 0)   ){

            if(centreLeftPosition%2 == 0 && centreRightPosition%2 == 0){
                --centreLeftPosition;
                ++centreRightPosition;
                continue;
            }

            if(maxLength < centreRightPosition/2 - centreLeftPosition/2 + 1){
                start = centreLeftPosition/2;
                maxLength = centreRightPosition/2 - centreLeftPosition/2 + 1;
            }
            --centreLeftPosition;
            ++centreRightPosition;
        }
        LPS[centrePosition] = maxLength;
        cout << " (" << centrePosition << "," << start << "," << maxLength << ") ";

        // we find a palindrome centred at centrePosition , startIndex = centreLeftPosition, endIndex = centreRightPosition

        //Run a loop towards right of centrePosition(id=centrePosition+1) and compute LPS[id] of all under this bug palindrome
        for(int currentRightPosition = centrePosition+1; currentRightPosition < centreRightPosition; currentRightPosition++){
            int currentLeftPosition = 2*centrePosition - currentRightPosition;
            int diff = (centreRightPosition - currentRightPosition)/2;

            //case 1, i-left palindrome is contained in palindrome centered at i && is contained in prefix of this big palindrome
            if(LPS[currentLeftPosition] < diff){
                //cout << "Case 1\n";
                LPS[currentRightPosition] = LPS[currentLeftPosition];
            }

            //case 2, i-left palindrome is prefix of palindrome centred at i && centre palindrome is suffix of input string s
            else if(LPS[currentLeftPosition] == diff && centreRightPosition == len-1){
                //cout << "Case 2\n";
                LPS[currentRightPosition] = LPS[currentLeftPosition];
            }

            //case 3,  i-left palindrome is prefix of palindrome centred at i && centre palindrome is not suffix of input string s
            //in this case L[currentRightPosition] >=  LPS[currentLeftPosition]
            //so we need to set it as centre (i.e. i = currentRightPosition) and check palindrome length around it
            else if(LPS[currentLeftPosition] == diff && centreRightPosition < len-1){
                //cout << "Case 3\n";
                LPS[currentRightPosition] = LPS[currentLeftPosition];
                centrePosition = currentRightPosition-1;
                expand = true;
                break;
            }

            //case 4, i-left pali11ndrome is NOT completely contained in center palindrome, i.e. goes beyond(on left side) of palindrome centred at i
            else if(LPS[currentLeftPosition] > diff){
                //cout << "Case 4\n";
                LPS[currentRightPosition] = diff;
                centrePosition = currentRightPosition-1;
                expand = true;
                break;
            }
        }

        if(!expand)
            centrePosition++;
    }
    cout << s.substr(start, maxLength);
    return s.substr(start, maxLength);
}

int main(){
    int T; cin >> T;
    string s;

    for(int t=0; t<T; t++){
        cin >> s;
        cout << longestPalindromeSubstring(s) << endl;
    }
    return 0;
}
