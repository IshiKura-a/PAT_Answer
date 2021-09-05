#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

int main() {
    int n;
    double p, r;
    std::cin >> n >> p >> r;

    std::vector<std::vector<int>> supply(n);
    std::vector<int> height(n, 0);
    std::vector<double> amount(n, 0);

    for (int i = 0; i < n; i++) {
        int k, to;
        std::cin >> k;
        for (int j = 0; j < k; j++) {
            std::cin >> to;
            supply[i].push_back(to);
        }
        if (!k) {
            std::cin >> amount[i];
        }
    }

    std::queue<int> q({0});
    double res = 0;
    while (!q.empty()) {
        auto front = q.front();
        auto v = supply[front];
        for (auto i: v) {
            height[i] = height[front] + 1;
            q.push(i);
        }
        if (v.empty()) {
            res += p * pow(1 + r / 100, height[front]) * amount[front];
        }
        q.pop();
    }

    printf("%.1lf", res);
    return 0;
}