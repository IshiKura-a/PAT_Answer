#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

int main() {
    int n;
    double p, r;
    std::cin >> n >> p >> r;

    std::vector<std::vector<int>> retailer(n + 1);
    std::vector<int> height(n + 1);

    int tmp;
    for (int i = 1; i <= n; i++) {
        std::cin >> tmp;
        retailer[tmp + 1].push_back(i);
    }

    std::queue<int> q({0});
    height[0] = -1;
    while (!q.empty()) {
        auto i = q.front();
        auto v = retailer[i];
        for (int j: v) {
            height[j] = height[i] + 1;
            q.push(j);
        }
        q.pop();
    }

    int maxHeight = height[0], cnt = 0;
    for (int i: height) {
        if (i > maxHeight) {
            maxHeight = i;
            cnt = 1;
        } else if (i == maxHeight) {
            cnt++;
        }
    }

    printf("%.2lf %d", p * pow(1 + r / 100.0, maxHeight), cnt);
    return 0;
}