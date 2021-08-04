#include <iostream>
#include <set>
#include <map>
#include <vector>

#define MAXN 100005

std::set<int> inCompatible[MAXN];

inline int min(int a, int b) {
    return a < b ? a : b;
}

inline int max(int a, int b) {
    return a > b ? a : b;
}

bool judge(int n) {
    std::vector<int> load;
    int tmp, i, j;
    for (i = 0; i < n; i++) {
        scanf("%d", &tmp);
        load.push_back(tmp);
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            int minNo = min(load[i], load[j]);
            int maxNo = max(load[i], load[j]);
            auto res = inCompatible[minNo].find(maxNo);
            if (res != inCompatible[minNo].end())
                return false;
        }
    }
    return true;
}

int main() {
    int N, M;

    std::cin >> N >> M;

    int i, a, b;
    for (i = 0; i < N; i++) {
        scanf("%d %d", &a, &b);
        inCompatible[min(a,b)].insert(max(a, b));
    }

    for (i = 0; i < M; i++) {
        int n;
        scanf("%d", &n);
        printf("%s\n", (judge(n) ? "Yes" : "No"));
    }
    return 0;
}