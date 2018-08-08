/*PROBLEM 6.12 FIND KTH PERMUTATION LEXICOGRAPHICALLY
ASSUMING IDENTITY/FIRST PERMUTATION IS 0,1,2,3,.....,N-1*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX_FACT 20
#define MAX_CHAR 26
ll fact[MAX_FACT];

//total number of permutation formed by N chars N!
//if there some repititions, the permutations = N! / (A! * B! * C! .....Z!)
//total number of permutation formed by setting char at first position (N-1)!
void precomputeFact(){
    fact[0] = 1;
    for(int i = 1; i < MAX_FACT; i++)
        fact[i] = fact[i-1]*i;
}

vector<int> kthPermutation(vector<int> &A, int n){
    precomputeFact();
    vector<int> result;
    int k = 0, sum = 0;
    //assuming all chars are unique, no repititions
    vector<int> freq(A.size(), 1);

    cout << "Inside function. Find " << n  << "th permutation." << endl;

    while(sum != n){
        sum = 0;
        //cout << "1\n";
        for(int i = 0; i < A.size(); i++){
            if(freq[i] == 0)
                continue;

            //cout << "2\n";
            //use this char
            freq[i]--;
            int xsum = fact[A.size()-1-k];
            //if no duplicates element are present then below loop is irrelevanet
            //for(int m = 0; m < MAX_CHAR; m++)
            //    xsum /= fact[freq[m]];
            sum += xsum;
            //cout << "sum,xsum:" << sum << "," << xsum << endl;

            if(sum >= n){
                //cout << "3\n";
                //cout <<  "Adding " << A[i] << " into Kth permutation.\n";
                result.push_back(A[i]);
                k++;
                n -= (sum - xsum);
                break;
            }

            if(sum < n){
                //cout << "4\n";
                //do not use this char for now
                freq[i]++;
            }
        }
    }
    //if n==sum, it means that this char(being fixed) will provide largest lexicograhic permutation
    //hence from
    for(int i = A.size()-1; i >= 0; --i){
        if(freq[i]){
            //cout <<  "Adding " << A[i] << " into kth permutation.\n";
            result.push_back(A[i]);
            freq[i]--;
        }
    }

    return result;
}

void printVector(vector<int> &A){
    for(int i=0; i<A.size(); i++)
        cout << A[i] << " ";
}

int main(){
    int N, K, X; cin >> N >> K;
    vector<int> A(N);
    for(int i=0; i<N; i++){
        cin >> X;
        A[i] = X;
    }
    vector<int> res = kthPermutation(A, K);
    printVector(res);
    return 0;
}
