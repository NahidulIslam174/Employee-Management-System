#include <stdio.h>

// Function to check if all elements have the same parity
int same_parity_of_jars(int N, int stones[]) {
    int is_even = 1;  // Assume even parity
    int is_odd = 1;   // Assume odd parity

    for (int i = 0; i < N; i++) {
        if (stones[i] % 2 == 0) {
            is_odd = 0;  // Not all are odd
        } else {
            is_even = 0;  // Not all are even
        }
    }

    // If either all are even or all are odd, then they have the same parity
    if (is_even || is_odd) {
        return 1;  // True
    } else {
        return 0;  // False
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int stones[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &stones[i]);
    }

    // Check and print the result
    if (same_parity_of_jars(N, stones)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

