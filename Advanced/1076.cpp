#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n, l, k;
    std::cin >> n >> l;
    std::vector<std::vector<int>> follower(n + 1);
    std::vector<bool> visit(n + 1, false);

    int m, follow;
    for (int i = 1; i <= n; i++) {
        std::cin >> m;
        for (int j = 0; j < m; j++) {
            std::cin >> follow;
            follower[follow].push_back(i);
        }
    }

    std::vector<int> res(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        std::fill(visit.begin(), visit.end(), false);
        std::queue<int> q({i});
        visit[i] = true;
        for (int j = 0; j < l; j++) {
            std::queue<int> r;
            while (!q.empty()) {
                auto front = q.front();
                for (auto p: follower[front]) {
                    if (!visit[p]) {
                        r.push(p);
                        cnt++;
                        visit[p] = true;
                    }
                }
                q.pop();
            }
            q = r;
        }
        res[i] = cnt;
    }

    std::cin >> k;
    for (int i = 0; i < k; i++) {
        int tmp;
        std::cin >> tmp;
        std::cout << res[tmp] << std::endl;
    }
    return 0;
}