
//GOOGLE
/*

Merge Overlapping Intervals
Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool compare(Interval a, Interval b){
    return a.start < b.start;
}

bool doesIntersect(Interval a, Interval b){
    if(min(a.end, b.end) < max(a.start, b.start)) return false;
    return true;
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    vector<Interval> ans;

    //corner cases
    if(n == 0)
        return {};

    if(n == 1)
        return A;

    sort(A.begin(), A.end(), compare);


    for(int i = 1; i < n; i++){
        bool intersect = doesIntersect(A[i-1], A[i]);

        //if do not intersect, push previous one
        if(!intersect){
            ans.push_back(A[i-1]);
        }
        else{
            //check how many overlaps
            while(i < n && intersect){

                //if intersects we make A[i] as new interval as = min(A[i-1].start, A[i].start), max(A[i-1].end, A[i].end)
                A[i].start =  min(A[i-1].start, A[i].start);
                A[i].end = max(A[i-1].end, A[i].end);
                i++;

                if(i == n)
                    intersect = false;
                else{
                    intersect = doesIntersect(A[i-1], A[i]);
                }

            }
            ans.push_back(A[i-1]);
        }
    }
    //if ans[ans.size-1].end is same as A[n-1].end hence ans is complete
    //else there is last interval missing in ans and add it
    if(ans[ans.size()-1].end != A[n-1].end)
        ans.push_back(A[n-1]);
    return ans;
}
