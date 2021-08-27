#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> v(N);
    for (int i = 0; i < N; i++) {
        std::cin >> v[i];
    }

    std::sort(v.begin(), v.end());
    int s1 = 0, s2 = 0;
    int i, j;
    for (i = 0, j = N - 1; i < j; i++, j--) {
        s1 += v[i];
        s2 += v[j];
    }
    if (i == j) {
        printf("%d %d", 1, std::max(abs(s1 + v[i] - s2), abs(s2 + v[i] - s1)));
    } else {
        printf("%d %d", 0, abs(s1 - s2));
    }
    return 0;
}