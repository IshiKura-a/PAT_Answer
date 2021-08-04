#include <iostream>
#include <cstring>

#define MAXN 205

int distance[MAXN][MAXN];
int visit[MAXN];

int main() {
    int N, M, K;
    std::cin >> N >> M;

    memset(distance, 0x3f, sizeof(distance));
    int i, j, x, y;
    for (i = 0; i < M; i++) {
        std::cin >> x >> y;
        std::cin >> distance[x][y];
        distance[y][x] = distance[x][y];
    }

    std::cin >> K;
    int n = 1;
    int minDistance = 0x3f3f3f3f;
    for (i = 0; i < K; i++) {
        memset(visit, 0, sizeof(visit));
        int k, d = 0, nVisit = 0, nVisitTwice = 0, first;
        std::cin >> k;
        for (j = 0; j < k; j++) {
            std::cin >> x;
            visit[x]++;
            if (visit[x] == 1) nVisit++;
            if (visit[x] > 1) nVisitTwice++;
            if (j != 0) {
                d += distance[x][y];
            } else {
                first = x;
            }
            y = x;
        }

        printf("Path %d: %s ", i + 1, d < 0x3f3f3f3f ? std::to_string(d).c_str() : "NA");
        if (nVisit < N || (nVisit == N && nVisitTwice < 1) || d >= 0x3f3f3f3f || first != x) {
            printf("(Not a TS cycle)\n");
        } else if (nVisitTwice > 1) {
            if (minDistance > d) {
                minDistance = d;
                n = i;
            }
            printf("(TS cycle)\n");
        } else {
            if (minDistance > d) {
                minDistance = d;
                n = i;
            }
            printf("(TS simple cycle)\n");
        }
    }
    printf("Shortest Dist(%d) = %d", n + 1, minDistance);

    return 0;
}

