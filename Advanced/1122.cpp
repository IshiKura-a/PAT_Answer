#include <iostream>
#include <set>

#define MAXN 205

bool adjacent[MAXN][MAXN];

int main() {
    int N, M, K;
    std::cin >> N >> M;
    int x, y;
    for (int i = 0; i < M; i++) {
        std::cin >> x >> y;
        adjacent[x][y] = adjacent[y][x] = true;
    }

    std::cin >> K;
    int n, prev, first, last, cnt;
    for (int i = 0; i < K; i++) {
        std::cin >> n;
        std::set<int> vertex;
        bool flag = true;
        cnt = 0;
        for (int j = 0; j < n; j++) {
            std::cin >> x;
            if(j == 0) {
                first = x;
            }
            if(j == n-1) {
                last = x;
            }
            if (flag && ((j && adjacent[prev][x]) || !j)) {
                if(vertex.find(x) != vertex.end()) {
                    cnt++;
                }
                vertex.insert(x);
            } else {
                flag = false;
            }
            prev = x;
        }
        std::cout << ((flag && vertex.size() == N && first == last && cnt == 1) ? "YES\n" : "NO\n");
    }
    return 0;
}