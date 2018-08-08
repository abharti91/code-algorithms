/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars.
For simplicity, assume that all bars have same width and the width is 1 unit.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array. The elements of the array represents the height of the bars.

Output:
In each seperate line the maximum rectangular area possible from the contigous bars.
Constraints:
1<=T<=30
1<=N<=100
1<=A[i]<=1000

Example:
Input:
1
7
6 2 5 4 5 1 6

Output:
12
*/
/*
1. traverse array
2. if stack is empty or a[i] is greater than stack top() then push
3. else keep popping(letsa say x) till we get top of stack smaller elements
3.1. for each pop we get compute area with x as smallest element
3.2. left_index = index of element at stack top after popping x
     right_index = index of a[i]
     area = x*(right_index - left_index -1);
*/
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int maxRectangularArea(int a[], int n){
    std::stack<int> st;
    int max = -1, area_top;

    int i;
    for (i = 0; i < n; i++) {
        if(st.empty() || a[st.top()] <= a[i]){
            st.push(i);
        }
        else{
            int curr;
            while(!st.empty() && a[st.top()] > a[i]){
                curr = st.top();
                st.pop();

                area_top = a[curr] * (st.empty() ? i : (i - st.top() - 1) );
                if(max < area_top)
                    max = area_top;
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        int curr = st.top();
        st.pop();

        area_top = a[curr] * (st.empty() ? i : (i - st.top() -1) );
        if(max < area_top)
            max = area_top;
    }

    return max;
}


int main(){
    int T, N; cin >> T;
    for(int t=0; t<T; t++){
        cin >> N;
        int a[N];
        for(int i = 0; i < N; i++){
            cin >> a[i];
        }
        cout << maxRectangularArea(a, N) << endl;
    }
}
