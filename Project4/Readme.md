Core Requirements



Algorithm

Implement kSmall function recursively.

Use the first element of the array as the pivot.

Partition the array around the pivot (implement a separate partition function).

The partition function:

Rearranges elements into S1 (≤ pivot), pivot, S2 (> pivot).

Returns the final index of the pivot.

Must handle cases where S1 is empty (e.g., 1 3 5 2 19 3 4 → pivot=1, S1 empty).

Continue recursion depending on whether k is in S1, pivot, or S2.




Function Requirements

Array must be passed as a pointer.

Use dynamic arrays (new operator) in main().



Testing

Test all 3 scenarios:

kth smallest in S1

kth smallest is the pivot

kth smallest in S2

Example given:
Array = {6, 3, 1, 10, 8, 4}, test with k=4 → 4th smallest = 6 (pivot).


Documentation

At the top of main.cpp, include:

Problem description

Your startID and name

Due date

Instructor

Comments

Use Javadoc-style comments for all functions.

Deliverables

Source Program (C++ code) – uploaded to GitHub.

Script File – showing multiple test runs on GitHub.

⚠️ Don’t include source code inside this file.

Word File

Contains test data, explanations, and user document.

User Document – must explain:

