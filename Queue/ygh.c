#include <stdio.h>
#include <stdlib.h>

typedef struct RoadConstruction {
    int A;
    int C;
} RoadConstruction;

// Function to find the parent of a set in the disjoint-set data structure
int findParent(int *parent, int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

// Function to perform union of two sets in the disjoint-set data structure
void unionSets(int *parent, int x, int y) {
    int xset = findParent(parent, x);
    int yset = findParent(parent, y);
    parent[xset] = yset;
}

// Function to compare two RoadConstruction objects based on their costs
int compareRoadConstruction(const void *a, const void *b) {
    return ((RoadConstruction *)a)->C - ((RoadConstruction *)b)->C;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    RoadConstruction *roads = (RoadConstruction *)malloc(M * sizeof(RoadConstruction));

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &roads[i].A, &roads[i].C);
    }

    // Sort the road constructions based on their costs
    qsort(roads, M, sizeof(RoadConstruction), compareRoadConstruction);

    // Initialize disjoint-set data structure
    int *parent = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        parent[i] = -1;
    }

    // Process road constructions
    long long totalCost = 0;
    for (int i = 0; i < M; i++) {
        int x = roads[i].A;
        int y = (x + roads[i].A) % N;

        int rootX = findParent(parent, x);
        int rootY = findParent(parent, y);

        // If x and y are not in the same set, connect them
        if (rootX != rootY) {
            unionSets(parent, rootX, rootY);
            totalCost += roads[i].C;
        }
    }

    // Check if all cities are connected
    int root = findParent(parent, 0);
    for (int i = 1; i < N; i++) {
        if (findParent(parent, i) != root) {
            printf("-1\n");
            free(roads);
            free(parent);
            return 0;
        }
    }

    // Print the minimum total cost
    printf("%lld\n", totalCost);

    free(roads);
    free(parent);

    return 0;
}
