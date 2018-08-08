/*
You are given two arrays of numbers. You have to maximize the first array by using the elements from the second array such that the new array formed contains unique elements.
For example, let the size of array be 'n'. Then the output should be n greatest but unique elements of both the arrays. The order of elements should be as explained in
example below, i.e., giving the second array priority.

Input:
The first line of each input contains the number of test cases . The description of T test cases follows:
The first line of each test case contains the size of the array (This is going to be the size of both the arrays).
The second line of each test case contains the elements of the first array.
The final line of each test case contains the elements of the second array.

Output:
Print the maximum elements giving second array higher priority. The order of appearance of elements is kept same in output as in input (See Example for better Understanding).

Constraints:
1 <= T <= 20
1 <= N <= 10
0 <= Array 1 [i] < =9
0 <= Array 2 [i] < =9

Example:
Input:
2
5
7 4 8 0 1
9 7 2 3 6
4
6 7 5 3
5 6 2 9

Output:
9 7 6 4 8
5 6 9 7

v1 -> 8 7 4 1 0
v2 -> 9 7 6 3 2

v11 -> (8,2) (4,1)
v21 -> (9,0) (7,1) (6,4)

after sorting in by second elements
v11 -> (4,1) (8,2)
v21 -> (9,0) (7,1) (6,4)
*/
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

//sort vector of pair based on first element in desceding order
bool sortRevOrderByFirst(const pair<int,int> &a, const pair<int,int> &b){
    if (a.first != b.first) {
        return a.first > b.first;
    }
    else{
        return a.second > b.second; 
    }
}

//sort vector of pair based on second element in ascending order
bool sortOrderBySecond(const pair<int,int> &a, const pair<int,int> &b){
    return a.second < b.second;
}

vector< pair<int,int> > maximizeArray(vector< pair<int,int> > v1, vector< pair<int,int> > v2, int n){

    std::sort(v1.begin(), v1.end(), sortRevOrderByFirst);
    std::sort(v2.begin(), v2.end(), sortRevOrderByFirst);

    //remove duplicate elements from own vector, will not work since we have pair
    //v1.erase(unique(v1.begin(), v1.end()), v1.end());
    //v2.erase(unique(v2.begin(), v2.end()), v2.end());

    //add elements from v1, v2 in descending order upto length of v1/v2
    //v11 stores element from v1 and v21 stores element from v2
    std::vector< pair<int,int> > v11;
    std::vector< pair<int,int> > v21;

    int i=0, j=0, count=0;

    //from two descending order sorted vactors pick n maximum elements
    while(i < v1.size() && j < v2.size() && count < n){
        if(i+1 < n && v1[i].first == v1[i+1].first){
            i++;
            continue;
        }

        if(i+1 < n && v2[j].first == v2[j+1].first){
            j++;
            continue;
        }

        if(v1[i].first > v2[j].first){
            v11.push_back(v1[i]);
            i++;
            count++;
        }
        else if(v1[i].first < v2[j].first){
            v21.push_back(v2[j]);
            j++;
            count++;
        }
        else{
            v21.push_back(v2[j]);
            i++;
            j++;
            count++;
        }
    }

    //lets say v1 finished but there are some elements in v2 left
    while(j < v2.size() && count < n){
        v21.push_back(v2[j]);
        j++;
        count++;
    }

    while(i < v1.size() && count < n){
        v11.push_back(v1[i]);
        i++;
        count++;
    }


    std::sort(v11.begin(), v11.end(), sortOrderBySecond);
    std::sort(v21.begin(), v21.end(), sortOrderBySecond);

    for(int i=0; i<v11.size(); i++)
        v21.push_back(v11[i]);

    return v21;
}


int main(){
    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int n, x; cin >> n;

        //to store element,index of all elements from array 1
        std::vector< std::pair<int,int> > v1;
        std::vector< pair<int,int> >::iterator it;

        for(int i=0; i<n; i++){
            cin >> x;
            v1.push_back(make_pair(x, i));
        }


        std::vector< std::pair<int,int> > v2;
        for(int i=0; i<n; i++){
            cin >> x;
            v2.push_back(make_pair(x, i));
        }

        std::vector< std::pair<int,int> > ans = maximizeArray(v1, v2, n);
        for (size_t i = 0; i < ans.size(); i++) {
            cout << ans[i].first << " ";
        }
        cout << endl;
    }
    return 0;
}
