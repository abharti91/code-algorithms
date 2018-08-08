#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<int> generatePrimes(){
    vector<int> primes;
    int isPrime[MAX];

    for(int i=0;i<MAX;i++)
        isPrime[i] = 1;

    for(int i = 2; i*i <= MAX; i++){

        if(isPrime[i]){
            primes.push_back(i);
            int j = 2;
            while(i*j <= MAX){
                isPrime[i*j] = 0;
                j++;
            }
        }
    }
    for(int i = 0; i < primes.size(); i++)
        cout << primes[i] << " ";
    return primes;
}


vector<int> primesum(int A) {

    vector<int> primes = generatePrimes();
    for(int i = 0; i < primes.size(); i++)
        cout << primes[i] << " ";


    vector<int> ans;

    /*for(int i=0; i<primes.size(); i++){
        for(int j=i; j<primes.size(); j++){
            if(primes[i] + primes[j] == A){
                ans.push_back(primes[i]);
                ans.push_back(primes[j]);
                return ans;
            }
        }
    }*/
    return ans;
}


int main(){
    vector<int> ans = generatePrimes();
    cout << ans[0] << " " << ans[1];
    return 0;
}
