#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    int M, N;
    std::cin >> M >> N;
    int i, p;

    std::unordered_set<int> set;
    std::vector<int> pre;

    for (i = 0; i < N; i++) {
        scanf("%d", &p);
        pre.push_back(p);
        set.insert(p);
    }

    int x, y, j;
    for (i = 0; i < M; i++) {
        scanf("%d%d", &x, &y);
        bool findX = set.find(x) != set.end();
        bool findY = set.find(y) != set.end();

        if (!findX) {
            if (!findY) {
                printf("ERROR: %d and %d are not found.\n", x, y);
            } else {
                printf("ERROR: %d is not found.\n", x);
            }
        } else if (!findY) {
            printf("ERROR: %d is not found.\n", y);
        } else {
            for (j = 0; j < N; j++) {
                if ((pre[j] >= x && pre[j] <= y) || (pre[j] >= y && pre[j] <= x)) {
                    break;
                }
            }
            if (pre[j] == x) {
                printf("%d is an ancestor of %d.\n", x, y);
            } else if (pre[j] == y) {
                printf("%d is an ancestor of %d.\n", y, x);
            } else {
                printf("LCA of %d and %d is %d.\n", x, y, pre[j]);
            }
        }

    }
    return 0;
}
