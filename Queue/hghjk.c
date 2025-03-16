#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    long long totalCost = 0;

    for (int i = 0; i < M; i++) {
        int A, C;
        scanf("%d %d", &A, &C);

        // If it's impossible to make all cities connected, print -1 and exit
        if (A >= N) {
            printf("-1\n");
            return 0;
        }

        // Calculate the cost of connecting all cities using the current road construction type
        totalCost += 1LL * A * C;

        // Check if all cities are connected
        if (totalCost > 2LL * (N - 1)) {
            printf("-1\n");
            return 0;
        }
    }

    // Print the minimum total cost
    printf("%lld\n", totalCost);

    return 0;
}
