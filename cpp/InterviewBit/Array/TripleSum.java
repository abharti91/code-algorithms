/*
Given an array of real numbers greater than zero in form of strings.
Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .
Return 1 for true or 0 for false.
*/


/*
Start tackling this problem by thinking of kinds of numbers that could be members of potential solutions. Think about what range those numbers could have. From this, these are the few scenarios under which a valid triplet could exist.

We have natural boundaries at 0, 1, and 2. So that leads to a few scenarios. Suppose we let A=(0,1] and we let B=(1,2). Then, any number in a potential solution must come from either range A or range B.

That leaves us with four unique combinations:

1.A, A, A
2.A, A, B
3.A, B, B
4.B, B, B

We can quickly deduce that case 3 and case 4 are not possible. The minimum value for range B is a little bit more than 1.
If we have two numbers that are a little bit more than 1, then our total sum will be a little bit more than 2. Say the numbers are 0.4, 1.0001 and 1.0001. Here sum is greater than 2. Hence, these cases won’t give us the required solution. Thus we can eliminate cases 3,4 and 5 (as they contain at least 2 numbers from range B).

So then we only have to check cases 1 and 2. Unfortunately, checking these cases is a little difficult. How can we determine if there are three numbers less than or equal to 1 that add up to a value greater than
1 and less than 2?

Maybe we can tighten the restrictions on case 1 to make it easier to solve. What if we knew that every number in range A was less than 2/3? Then we could just
select the three highest values in A. If those three numbers exist and add up to a value in the range (1,2), then case 1 is fulfilled. Example- Let highest numbers in A be 0.333,0.55,0.44.
These three numbers lies in the required range(1,2) and hence would give us the solution.

Now, since we tightened the restriction in case 1, we need another case to cover when values are in the range [2/3,1].

Let us formally define our new ranges. Let A=(0,2/3), B=[2/3,1] and C=(1,2).
These new ranges leave us with ten unique combinations:

1.A, A, A
2.A, A, B
3.A, A, C
4.A, B, B
5.A, B, C
6.A, C, C
7.B, B, B
8.B, B, C
9.B, C, C
10.C, C, C

We can quickly deduce that cases 6, 7, 8, 9, and 10 are not possible (the total sum will always be greater than 2).

That leaves us with cases 1, 2, 3, 4, and 5.

We can check case 1 by looking at the three largest values in A. Say we have these highest values as : 0.500,0.6666,0.65777.
This lies between 1 and 2. We only have to worry about underflow in this case, meaning the sum of highest values in this range may not be greater than 1.
But we are sure that this will be less than 2. So we only have to check for the condition whether these are greater than 1 or not.

Now, what about case 2? Under case 2, we have two numbers in range A and one number in range B. We have to worry about underflow and overflow.
To avoid underflow, let’s suppose that we select the two largest values in A. Let’s call the sum of those numbers s. The range of s will be (0,4/3).
So we just need to determine if there is a value in B that is greater than 1−s and less than 2−s. Simple enough.

Under case 3, we have two numbers in range A and one number in range C. We just have to worry about overflow ( because to the presence of an integer from range C,
we are sure that their sum will be greater than 1). To avoid overflow, let’s suppose that we select the two smallest values in A and the smallest value in C.
 If the sum of those numbers is in the range ((1,2), then this case has occurred.

Case 4 will be similar to case 2. Under case 4, we have one number in range A and two numbers in range B. We have to worry about overflow.
 To avoid overflow, let’s suppose that we select the two smallest values in BB. Let’s call the sum of those numbers s. The range of ss will be [4/3,2].
 So we just need to determine if there is a value in A that is less than 2−s. Not bad.

Case 5 is pretty easy as well. We have to worry about overflow. To avoid overflow, let’s suppose that we select the smallest value in A, the smallest value in B,
and the smallest value in C. If the sum of those numbers is in the range (1,2), then this case has occurred.

So, to solve the problem, we just check to see if case 1, 2, 3, 4, or 5 is satisfied. Each case can be checked in O(n) time.

We can conclude that for all the 5 possible cases, we just need 3 largest values in range A, 2 smallest in range B, 2 smallest in range A and the smallest in range C.
 There are a lot of methods, choose anyone to find them.
*/

import java.util.Collections;
import java.util.ArrayList;
import java.util.Vector;

public class TripleSum {
    public int solve(ArrayList<String> v) {
        int n = v.size();
        if(n < 3)
            return 0;

        Float f = 0.0f;
        Vector<Float> A = new Vector<Float>();
        Vector<Float> B = new Vector<Float>();
        Vector<Float> C = new Vector<Float>();

        for(int i=0; i<n; i++){
            f = Float.valueOf(v.get(i));

            //c1>0 if f>2/3  , c1<0 if f<2/3 , c1==0 if f==2/3
            int c1 = Float.compare(f, 0.666666666666666f);
            int c2 = Float.compare(f, 1.0f);

            if(c1 < 0)
                A.add(f);
            else if(c1 >= 0 && c2 <= 0)
                B.add(f);
            else
                C.add(f);
        }


        Collections.sort(A);
        Collections.sort(B);
        Collections.sort(C);

        int a = A.size(), b = B.size(), c = C.size(), i;
        Float sum = 0.0f;

        for(i=0; i<a; i++)
            System.out.print(A.get(i) + " ");
        System.out.println();

        for(i=0; i<b; i++)
            System.out.print(B.get(i) + " ");
         System.out.println();

        for(i=0; i<c; i++)
            System.out.print(C.get(i) + " ");
        System.out.println();


        //valid case AAA, AAB, AAC, ABB, ABC
        //AAA - underflow => get largest three numbers sum and check if sum is > 1, if yes we found triplet
        if(a >= 3){
            sum = A.get(a-1) + A.get(a-2) + A.get(a-3);
            if(sum > 1.0f)
                return 1;
        }


        //AAB - underflow => (AA sum s = (0, 4/3), adding B[2/3, 1] may cause underflow 0.1+0.1+0.6)
        //      overflow  => (AA sum s = (0, 4/3), adding B[2/3, 1] may cause overflow 0.6+0.6+0.9)
        if(a >= 2 && b >= 1){
            //underflow
            sum = A.get(0) + A.get(1);
            for(i=0; i<b; i++){
                if(1.0f < sum+B.get(i)  && sum+B.get(i) < 2.0f)
                    return 1;
            }

            //overflow
            sum = A.get(a-1) + A.get(a-2);
            for(i=0; i<b; i++){
                if(1.0f < sum+B.get(i) && sum+B.get(i) < 2.0f)
                    return 1;
            }
        }


        //AAC - overflow => (since C make sure we have sum > 1) sum of two smallest from  A + smallest from C < 2
        if(a >= 2 && c >= 1){
            sum = A.get(0) + A.get(1) + C.get(0);
            if(sum < 2.0f)
                return 1;
        }


        //ABB - no underflow => (A(0, 2/3) BB [4/3, 2] may cause underflow 0.1+0.6+0.6 > 1)
        //      overflow => may cause 0.3+0.7+0.7
        if(a >= 1 && b >= 2){
            sum = B.get(0) + B.get(1);
            for(i=0; i<a; i++){
                if(1.0f < sum+A.get(i) && sum+A.get(i) < 2.0f)
                    return 1;
            }
        }


        //ABC - overflow pick smallest value from A, B, C
        if(a >= 1 && b >= 1 && c >= 1){
            sum = A.get(0) + B.get(0) + C.get(0);
            if(1.0f < sum && sum < 2.0f)
                return 1;
        }

       return 0;
    }


    public static void main(String args[]){
        TripleSum o = new TripleSum();
        ArrayList<String> list = new ArrayList<String>();
        list.add("2.673662"); list.add("2.419159"); list.add("0.573816"); list.add("2.454376"); list.add("0.403605"); list.add("2.503658"); list.add("0.806191");
        System.out.println(o.solve(list));
    }



}
