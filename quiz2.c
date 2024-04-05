#include <stdio.h>

void circular_shift(int A[], int n, int k) {
    k = k % n; // Handle k greater than or equal to n (full rotations)

    // Reverse the entire array
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    // Reverse the first k elements
    for (int i = 0, j = k - 1; i < j; i++, j--) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    // Reverse the remaining elements (n-k to n-1)
    for (int i = k, j = n - 1; i < j; i++, j--) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

int main() {
    int A[] = {5, 15, 29, 35, 42};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 2;

    circular_shift(A, n, k);

    printf("Shifted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
