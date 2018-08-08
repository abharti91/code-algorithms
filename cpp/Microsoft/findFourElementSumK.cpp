//O(n2 logn) algorithm O(n2) aux space
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

struct pairSum{
    int first;
    int second;
    int sum;
};

bool compare(struct pairSum p1, struct pairSum p2){
    return p1.sum < p2.sum;
}

bool exclusive(struct pairSum p1, struct pairSum p2){
    if(p1.first == p2.first || p1.first == p2.second
        || p1.second == p2.first || p1.second == p2.second)
        return false;
    else
        return true;
}

void print(struct pairSum ps[], int n){
    cout  << " sorted array :";
    for(int i=0; i<n; i++){
        cout << "(" << ps[i].first << "," << ps[i].second << "," << ps[i].sum << ") " ;
    }
}

void findFourElementSumK(int a[], int n, int K){
    int size = (n * (n-1))/2;
    struct pairSum ps_aux[size];

    //make an auxilary array to store sum of every two elments, along with values of both elements
    //time -> O(n2)
    int k=0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            ps_aux[k].sum = a[i] + a[j];
            ps_aux[k].first = a[i];
            ps_aux[k].second = a[j];
            k++;
        }
    }

    //sorting -> O(n2 logn2)
    sort(ps_aux, ps_aux+size, compare);
    //print(ps_aux, size);

    //run left/right indexed and get if their sum matches K -> O(n2)
    //store sorted vector into vector array , also skip if element(vector) exsists in v_arr
    vector< vector<int> > v_arr;
    int i=0, j=size-1;
    while(i < j){
        if(ps_aux[i].sum + ps_aux[j].sum == K &&
                            exclusive(ps_aux[i], ps_aux[j]) ){
            vector<int> v;
            v.push_back(ps_aux[i].first);  v.push_back(ps_aux[i].second);  v.push_back(ps_aux[j].first);  v.push_back(ps_aux[j].second);
            std::sort(v.begin(), v.end());

            //check if object/vector already exists, if not then add it to array of vectors
            if(std::find(v_arr.begin(), v_arr.end(), v) == v_arr.end())
                v_arr.push_back(v);
            i++;
            j--;
        }

        if(ps_aux[i].sum + ps_aux[j].sum < K)
            i++;
        else
            j--;
    }

    //way to print a vector of vector (2 dimensional vector)
    vector< vector<int> >::iterator row;
    vector<int>::iterator col;
    for(row = v_arr.begin(); row != v_arr.end(); row++){
        for(col = row->begin(); col != row->end(); col++)
            cout << *col << " ";
        cout << endl;
    }

}

int main(int argc, char const *argv[]) {
    int T, n, k;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n >> k;
        int *a;
        a = new int[n];
        for(int j=0; j<n; j++){
            cin >> a[j];
        }

        findFourElementSumK(a, n, k);
    }
  return 0;
}
