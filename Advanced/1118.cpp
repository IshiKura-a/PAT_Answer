#include <iostream>
#include <set>

#define MAXN 10005

int forest[MAXN];

int main() {
    int N, K, Q, maxN = 0;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> K;
        int curMin = MAXN, cur;
        for (int j = 0; j < K; j++) {
            std::cin >> cur;
            if (cur > maxN) maxN = cur;
            if (cur < curMin) {
                forest[curMin] = cur;
                curMin = cur;
            }
            if (!forest[cur]) {
                forest[cur] = curMin;
            } else {
                if (curMin < forest[cur]) {
                    forest[forest[cur]] = curMin;
                    forest[cur] = curMin;
                } else if (curMin > forest[cur]) {
                    forest[curMin] = forest[cur];
                    curMin = forest[cur];
                }
            }
        }
    }

    std::set<int> group;
    for (int i = 1; i <= maxN; i++) {
        int cur = forest[i];
        while (cur != forest[cur]) cur = forest[cur];
        forest[i] = cur;
        group.insert(cur);
    }

    printf("%d %d\n", group.size(), maxN);
    std::cin >> Q;
    int x, y;
    for (int i = 0; i < Q; i++) {
        std::cin >> x >> y;
        std::cout << (forest[x] == forest[y] ? "Yes\n" : "No\n");
    }

    return 0;
}