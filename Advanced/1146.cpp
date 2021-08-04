#include <iostream>
#include <vector>
#include <cstring>

#define MAXN 1005

bool preceed[MAXN][MAXN];

int main() {
    int N, M, K;
    int i, j;
    std::cin >> N >> M;

    memset(preceed, 0, sizeof(preceed));
    int x, y;
    for (i = 0; i < M; i++) {
        std::cin >> x >> y;
        preceed[x][y] = true;
    }

    std::cin >> K;
    std::vector<int> err;
    for (i = 0; i < K; i++) {
        std::vector<int> arr;
        for (j = 0; j < N; j++) {
            std::cin >> x;
            arr.push_back(x);
        }

        bool flag = true;
        int k;
        for (j = 1; j < N; j++) {
            for (k = 0; k < j; k++) {
                if (preceed[arr[j]][arr[k]]) {
                    flag = false;
                    break;
                }
            }
        }
        if (!flag) err.push_back(i);
    }

    for (int item:err) {
        printf("%d", item);
        if (item != err.back()) printf(" ");
    }

    return 0;
}