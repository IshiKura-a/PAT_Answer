#include <iostream>
#include <vector>

#define MAXN 505

bool adjacent[MAXN][MAXN];

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> cnt(N + 1);

    std::fill(cnt.begin(), cnt.end(), 0);

    int x, y;
    for (int i = 0; i < M; i++) {
        std::cin >> x >> y;
        cnt[x]++;
        cnt[y]++;

        adjacent[x][y] = adjacent[y][x] = true;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (adjacent[i][j] && adjacent[j][k]) {
                    adjacent[i][k] = true;
                }
            }
        }
    }
    bool connected = true;
    for (int i = 2; i <= N; i++) {
        connected &= adjacent[1][i];
    }

    int nOdd = 0;
    for (int i = 1; i <= N; i++) {
        printf("%d", cnt[i]);
        if (cnt[i] % 2) nOdd++;
        if (i != N) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    if (nOdd == 0 && connected) {
        printf("Eulerian");
    } else if (nOdd == 2 && connected) {
        printf("Semi-Eulerian");
    } else {
        printf("Non-Eulerian");
    }

    return 0;
}