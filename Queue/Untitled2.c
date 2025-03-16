#include <stdio.h>

// Function to perform bubble sort on the array
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int runs[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &runs[i]);
    }

    // Sort the array using bubble sort
    bubbleSort(runs, N);

    // Print the sorted array
    for (int i = 0; i < N; i++) {
        printf("%d ", runs[i]);
    }
    printf("\n");

    // Count the number of matches Shanto performed well
    int well_performed = 0;
    for (int i = 0; i < N; i++) {
        if (runs[i] > 50) {
            well_performed++;
        }
    }

    // Print the number of matches Shanto performed well
    printf("%d\n", well_performed);

    return 0;
}

