#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

const int MAXN = 1020;
double distance[MAXN][MAXN];

int main() {
    int n, m, k, ds;
    std::cin >> n >> m >> k >> ds;

    std::fill(distance[0], distance[0] + MAXN * MAXN, 1e20);
    std::string p, q;
    int x, y;
    double dist;
    for (int i = 0; i < k; i++) {
        std::cin >> p >> q >> dist;
        auto s = p.substr(p[0] == 'G' ? 1 : 0);
        auto t = q.substr(q[0] == 'G' ? 1 : 0);
        x = std::stoi(s) + (p[0] == 'G' ? n : 0);
        y = std::stoi(t) + (q[0] == 'G' ? n : 0);

        distance[x][y] = dist;
        distance[y][x] = dist;
    }

    std::vector<bool> visit(n + m + 1, false);
    for (int i = n + 1; i <= n + m; i++) {
        std::fill(visit.begin(), visit.end(), false);
        for (int r = 1; r <= n + m; r++) {
            double min = 1e20;
            int node = -1;
            for (int j = 1; j <= n + m; j++) {
                if (!visit[j] && distance[i][j] < min) {
                    node = j;
                    min = distance[i][j];
                }
            }
            if (node == -1) break;
            visit[node] = true;
            for (int j = 1; j <= n + m; j++) {
                if (!visit[j] && distance[i][j] > distance[i][node] + distance[node][j]) {
                    distance[i][j] = distance[i][node] + distance[node][j];
                }
            }
        }
    }

    bool flag;
    double optMin = 0, optTotal, curMin, curTotal;
    int res = 0;
    for (int i = n + 1; i <= n + m; i++) {
        flag = true;
        curMin = distance[i][0];
        curTotal = 0;
        for (int j = 1; j <= n; j++) {
            if (distance[i][j] > ds) {
                flag = false;
                break;
            }
            curMin = curMin < distance[i][j] ? curMin : distance[i][j];
            curTotal += distance[i][j];
        }
        if (flag) {
            if (optMin < curMin ||
                (optMin == curMin && optTotal > curTotal)) {
                optMin = curMin;
                optTotal = curTotal;
                res = i - n;
            }
        }
    }
    if (res > 0) {
        printf("G%d\n", res);
        std::cout << std::fixed << std::setprecision(1) << optMin << " "
                  << std::fixed << std::setprecision(1) << std::round(optTotal * 10.0 / n) / 10;
    } else {
        printf("No Solution");
    }
    return 0;
}