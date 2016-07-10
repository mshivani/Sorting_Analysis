
PROBLEM: 

Choosing one algorithm can severely impact your overall time and complexity

In our code we aim to cut down the overall time when using a big variety array sizes

Our function analyzes a given array, chooses which algorithm is best to run on the given array and runs the algorithm on the array



SOLUTION:

Insertion:    Best case - mostly sorted or small arrays
Bucket:       Best case - Large arrays

Merge and Quick sort have a decent average case, so we used them to cover the worst case of other the other two.


InsertionPoints: Used to determine how sorted the array already is
In O(n) time we go through the loop to characterize the array

