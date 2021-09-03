#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> v(N);
    std::vector<int> min(N);
    std::vector<int> max(N);
    std::vector<int> pivot;

    for (int i = 0; i < N; i++) {
        std::cin >> v[i];
        min[i] = v[i];
        max[i] = v[i];
        if (i) {
            max[i] = std::max(max[i], max[i - 1]);
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        if (i != N - 1) min[i] = std::min(min[i], min[i + 1]);
        if (v[i] <= min[i] && v[i] >= max[i]) {
            pivot.push_back(v[i]);
        }
    }

    printf("%d\n", pivot.size());
    std::sort(pivot.begin(), pivot.end());
    for (auto i = pivot.begin(); i != pivot.end(); i++) {
        if (i != pivot.begin()) {
            printf(" ");
        }
        printf("%d", *i);
    }
    printf("\n");
    return 0;
}