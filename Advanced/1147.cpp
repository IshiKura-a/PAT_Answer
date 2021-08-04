#include <iostream>

#define MAXN 1005

/*
 * heap[0]:
 * 0: none
 * 1: min
 * -1: max
 */
int N, M;
int heap[MAXN];

void dfs(int node);

void printHeap(int node);

int main() {
    int i, j;
    std::cin >> M >> N;

    for (i = 0; i < M; i++) {
        for (j = 1; j <= N; j++) {
            std::cin >> heap[j];
        }
        if (heap[2] > heap[1]) {
            heap[0] = 1;
        } else if (heap[2] == heap[1]) {
            heap[0] = 0;
        } else {
            heap[0] = -1;
        }
        dfs(1);
        printf("%s\n", heap[0] < 0 ? "Max Heap" : (heap[0] > 0 ? "Min Heap" : "Not Heap"));
        printHeap(1);
        printf("\n");
    }
    return 0;
}

void dfs(int node) {
    if (node <= N) {
        if (2 * node <= N) {
            if ((heap[0] > 0 && heap[node] >= heap[2 * node]) || (heap[0] < 0 && heap[node] <= heap[2 * node])) {
                heap[0] = 0;
            }
            dfs(2 * node);
            if (2 * node + 1 <= N) {
                if ((heap[0] > 0 && heap[node] >= heap[2 * node + 1]) ||
                    (heap[0] < 0 && heap[node] <= heap[2 * node + 1])) {
                    heap[0] = 0;
                }
                dfs(2 * node + 1);
            }
        }
    }
}

void printHeap(int node) {
    if (node <= N) {
        if (2 * node <= N) {
            printHeap(2 * node);
            if (2 * node + 1 <= N) {
                printHeap(2 * node + 1);
            }
        }
        printf("%d", heap[node]);
        if (node != 1) printf(" ");
    }
}