/* 
Find if two rectangles overlap
--------------------------------
Given eight integers A, B, C, D, E, F, G and H which represent two rectangles in a 2D plane. 
For the first rectangle it's bottom left corner is (A, B) and top right corner is (C, D) 
and for the second rectangle it's bottom left corner is (E, F) and top right corner is (G, H). 
Find and return whether the two rectangles overlap or not. 

Input Format
The eight arguments given are the integers A, B, C, D, E, F, G and H.

Output Format
Return 1 if the two rectangles overlap else return 0.

Constraints
-10000 <= A < C <= 10000
-10000 <= B < D <= 10000
-10000 <= E < G <= 10000
-10000 <= F < H <= 10000

For Example
Input 1:
    A = 0   B = 0
    C = 4   D = 4
    E = 2   F = 2
    G = 6   H = 6
Output 1:
    1

Input 2:
    A = 0   B = 0
    C = 4   D = 4
    E = 2   F = 2
    G = 3   H = 3
Output 2:
    1

 */

/* Solution Explanation 
https://stackoverflow.com/questions/306316/determine-if-two-rectangles-overlap-each-other */

int Solution::solve(int A, int B, int C, int D, int E, int F, int G, int H) {
    
    if (
        A < G && 
        C > E &&
        D > F &&
        B < H
        )
        return 1;
    else
        return 0;
}


/* Solution Explanation 
https://stackoverflow.com/questions/306316/determine-if-two-rectangles-overlap-each-other */
/* 

if (RectA.Left < RectB.Right && RectA.Right > RectB.Left &&
     RectA.Top > RectB.Bottom && RectA.Bottom < RectB.Top ) 
or, using Cartesian coordinates

(With X1 being left coord, X2 being right coord, increasing from left to right and Y1 being Top coord, and Y2 being Bottom coord, increasing from bottom to top) ...

if (RectA.X1 < RectB.X2 && RectA.X2 > RectB.X1 &&
    RectA.Y1 > RectB.Y2 && RectA.Y2 < RectB.Y1) 
Say you have Rect A, and Rect B. Proof is by contradiction. Any one of four conditions guarantees that no overlap can exist:

Cond1. If A's left edge is to the right of the B's right edge, - then A is Totally to right Of B
Cond2. If A's right edge is to the left of the B's left edge, - then A is Totally to left Of B
Cond3. If A's top edge is below B's bottom edge, - then A is Totally below B
Cond4. If A's bottom edge is above B's top edge, - then A is Totally above B
So condition for Non-Overlap is

Cond1 Or Cond2 Or Cond3 Or Cond4
Therefore, a sufficient condition for Overlap is the opposite.

Not (Cond1 Or Cond2 Or Cond3 Or Cond4)
De Morgan's law says
Not (A or B or C or D) is the same as Not A And Not B And Not C And Not D
so using De Morgan, we have

Not Cond1 And Not Cond2 And Not Cond3 And Not Cond4
This is equivalent to:

A's Left Edge to left of B's right edge, [RectA.Left < RectB.Right], and
A's right edge to right of B's left edge, [RectA.Right > RectB.Left], and
A's top above B's bottom, [RectA.Top > RectB.Bottom], and
A's bottom below B's Top [RectA.Bottom < RectB.Top]
Note 1: It is fairly obvious this same principle can be extended to any number of dimensions.
Note 2: It should also be fairly obvious to count overlaps of just one pixel, change the < and/or the > on that boundary to a <= or a >=.
Note 3: This answer, when utilizing Cartesian coordinates (X, Y) is based on standard algebraic Cartesian coordinates (x increases left to right, and Y increases bottom to top). Obviously, where a computer system might mechanize screen coordinates differently, (e.g., increasing Y from top to bottom, or X From right to left), the syntax will need to be adjusted accordingly/

 */