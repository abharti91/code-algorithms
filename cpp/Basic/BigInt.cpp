/*Problem 6.9 MULTIPLY TWO INTEGERS REPRESENTED BY BIG INTEGERS
USE OF OPERATOR OVERLOADING */

#include<bits/stdc++.h>
using namespace std;

class BigInt{
    private:
        int sign;//-1 or 1
        vector<int> digits;

    public:
        BigInt(const int &capacity) : sign(1), digits(capacity){}

        BigInt(const string &s) : sign(s[0] == '-' ? -1 : 1),
                                  digits(s.size() - (s[0] == '-')){
            //converting string into char array digits but in reverse order
            for(int i = s.size()-1, j = 0; i >= (s[0] == '-'); i--, j++){
                if(isdigit(s[i])){
                    digits[j] = s[i] - '0';
                    //cout << digits[j];
                }
            }
            //cout << endl;
        }

        //outer for loop iterate over n of len n.digits.size()
        //inner for loop iterate over m of len digits.size()
        //result would be of size m+n
        BigInt operator*(const BigInt &n) const{
            BigInt result(digits.size() + n.digits.size());
            result.sign = sign * n.sign;
            int i, j;

            for(i = 0; i < n.digits.size(); ++i){
                int carry = 0;
                for(j = 0; j < digits.size() || carry; ++j){
                    //adding result.digits[i+j] helps to add previous rows output into current one
                    int d = result.digits[i+j] + (j < digits.size() ? n.digits[i] * digits[j] : 0) + carry;
                    result.digits[i+j] = d%10;
                    //cout << "i:"<< i << ",j:" << j << "=" << result.digits[i+j] << endl;
                    carry = d/10;
                }
            }

            //if one of them is 0
            if(digits.size() == 1 && digits.front() == 0 || n.digits.size() == 1 && n.digits.front() == 0){
                result.digits.resize(1);
            }
            else{
                result.digits.resize(i+j-1);
            }
            return result;
        }

        void printInt(){
            //reverse the output
            int i = 0, j = digits.size()-1;
            reverse(digits.begin(), digits.end());
            /*while(i < j){
                digits[i] = digits[i]^digits[j];
                digits[j] = digits[i]^digits[j];
                digits[i] = digits[i]^digits[j];
                i++; j--;
            }*/

            cout << "Output of multiplication : ";
            cout << ((sign == -1) ? "-" : "");
            //skip exta 0's in front
            i = 0;
            while(digits[i] == 0)
                i++;
            for(; i < digits.size(); i++){
                cout << digits[i];
            }
        }
};


int main(){
    BigInt S1("2222"), S2("5");
    BigInt multiply = S1*(S2);
    multiply.printInt();
    return 0;
}
