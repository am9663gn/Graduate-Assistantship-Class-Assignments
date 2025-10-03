/**
 * @file main.cpp
 * @brief Recursive solution for finding the kth smallest element in an array
 *
 * Problem: Implement the kSmall algorithm using recursion and partitioning.
 * The first element of the array is used as the pivot. The array is passed
 * as a pointer, and dynamic memory allocation is used in main().
 *
 * @author [Your Name]
 * @startID [Your StartID]
 * @course CSCI 301 – Computer Science II
 * @instructor [Instructor Name]
 * @due_date October 13
 */

#include <iostream>
#include <stdexcept>
using namespace std;

/**
 * @brief Partition the array around the pivot (first element).
 *
 * @param arr Pointer to the array
 * @param left Starting index
 * @param right Ending index
 * @return The final index of the pivot after partition
 *
 * @pre arr must be a valid pointer and indices within bounds.
 * @post Elements are rearranged so that those <= pivot are on the left,
 *       pivot is at its correct position, and larger elements are on the right.
 */
int partition(int *arr, int left, int right) {
    int pivot = arr[left];
    int i = left + 1;
    int j = right;

    while (true) {
        while (i <= right && arr[i] <= pivot) i++;
        while (j >= left + 1 && arr[j] > pivot) j--;

        if (i > j) break;
        swap(arr[i], arr[j]);
    }

    swap(arr[left], arr[j]); // place pivot in correct position
    return j;
}

/**
 * @brief Recursive function to find kth smallest element.
 *
 * @param arr Pointer to the array
 * @param left Starting index
 * @param right Ending index
 * @param k Index (1-based) of kth smallest element
 * @return The kth smallest element
 *
 * @pre 1 <= k <= (right - left + 1)
 * @post Returns the kth smallest element of the array
 */
int kSmall(int *arr, int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = partition(arr, left, right);

        int rank = pivotIndex - left + 1; // position of pivot in current array

        if (k == rank) {
            return arr[pivotIndex]; // kth smallest is pivot
        } else if (k < rank) {
            return kSmall(arr, left, pivotIndex - 1, k); // kth in left subarray
        } else {
            return kSmall(arr, pivotIndex + 1, right, k - rank); // kth in right
        }
    }

    throw invalid_argument("k is out of range");
}

/**
 * @brief Main function to test kSmall.
 */
int main() {
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be positive." << endl;
        return 1;
    }

    int *arr = new int[n]; // dynamic allocation

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter k (1-based index): ";
    cin >> k;

    if (k < 1 || k > n) {
        cout << "Error: k is out of range" << endl;
        delete[] arr;
        return 1;
    }

    try {
        int result = kSmall(arr, 0, n - 1, k);
        cout << "The " << k << "th smallest element is " << result << endl;
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }

    delete[] arr; // free memory
    return 0;
}
