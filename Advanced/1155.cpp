#include <iostream>
#include <vector>

#define MAXN 1005
int N;
int heap[MAXN];
std::vector<int> nodes;
/*
 * 0: none
 * 1: min
 * -1: max
 */
int minMax;

void dfs(int node);

int main() {
    int i;
    std::cin >> N;
    for (i = 0; i < N; i++) {
        std::cin >> heap[i];
    }

    if (heap[1] > heap[0]) {
        minMax = 1;
    } else if (heap[1] == heap[0]) {
        minMax = 0;
    } else {
        minMax = -1;
    }
    dfs(1);
    printf("%s", minMax < 0 ? "Max Heap" : (minMax > 0 ? "Min Heap" : "Not Heap"));
}

void dfs(int node) {
    if (node <= N) {
        nodes.push_back(heap[node - 1]);
        if (2 * node <= N) {
            if (2 * node + 1 <= N) {
                dfs(2 * node + 1);
            }
            dfs(2 * node);
        } else {
            int i;
            for (i = 0; i < nodes.size(); i++) {
                printf("%d%c", nodes[i], i == (nodes.size() - 1) ? '\n' : ' ');
                if (i > 0) {
                    if ((minMax > 0 && nodes[i - 1] >= nodes[i]) || (minMax < 0 && nodes[i - 1] <= nodes[i])) {
                        minMax = 0;
                    }
                }
            }
        }
        nodes.pop_back();
    }
}