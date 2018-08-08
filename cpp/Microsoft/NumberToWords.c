/*
Given number into words. For example, if “1234” is given as input, output should be “one thousand two hundred and thirty four”

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N.

Output:

Print the number into words (in small letter).
*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

//logic to reverse a char array
char* rev(char *s){
    if(strlen(s) == 0 || strlen(s) == 1)
        return s;

    int i=0, j=strlen(s)-1;
    while(i<j){
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++;
        j--;
    }
    return s;
}

//code to convert integer to char array
char* toArray(int num){
    int i;
    int n = log10(num) + 1;
    char* char_arr = malloc( (n+1) * sizeof(char));
    for(i=0; i<n; ++i, num=num/10){
        char_arr[i] = num%10 + '0';
    }
    char_arr[i] = '\0';
    return rev(char_arr);
}


void convertToWords(char *num){
    int len = strlen(num); int x = len;
    char* single_digits[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    char* two_digits[] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    char* ten_digits[] = {"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    char* hundred_digits[] = {"hundred","thousand"};

    if (len == 1) {
        printf("%s", single_digits[*num-'0']);
        return;
    }

    while(*num != '\0'){
        //prepare thousand & hundred place, length of num being 3 or 4
        if(len >= 3){
            //this is to save printing like 4 thousands 0 hundred
            if(*num-'0'){
                printf("%s ", single_digits[*num-'0']);
                printf("%s ", hundred_digits[len-3]);
            }
            --len;
        }
        //else runs only once
        else{
            if(x >= 3 && (*num-'0' != 0 || *(num+1)-'0' != 0))
                printf("and ");

            //handles numbers from 10-19
            if(*num-'0' == 1){
                printf("%s ", two_digits[*(num+1)-'0']);
                return;
            }
            //handles numbers 20,30,40,..,90
            else if(*(num+1)-'0' == 0){
                printf("%s ", ten_digits[*num-'0']);
                return;
            }
            //handles numbers 0-9 and 21-99
            else{
                int i = *num-'0';
                if(i)
                    printf("%s ", ten_digits[*num-'0']);
                ++num;
                printf("%s ", single_digits[*num-'0']);
            }
        }
        ++num;
    }

}


int main(){
    int T, n, t;
    scanf("%d",&T);
    char* num;

    for(t=0; t<T; t++){
        scanf("%d", &n);
        //printf("%s\n", toArray(n));
        convertToWords(toArray(n));
        printf("\n");
    }
    return 0;
}
