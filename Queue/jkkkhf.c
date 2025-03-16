#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int stones[N];

    // Read the stones in each jar
    for (int i = 0; i < N; i++) {
        scanf("%d", &stones[i]);
    }

    // Check if each jar has the same parity of stones
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
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
