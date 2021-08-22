#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<double> rope(N);
    for (int i = 0; i < N; i++) {
        std::cin >> rope[i];
    }

    std::sort(rope.begin(), rope.end());
    double p = 1;
    double total = 0;
    for (int i = N - 1; i > 0; i--) {
        p *= 0.5;
        total += rope[i] * p;
    }
    total += rope[0] * p;

    std::cout << (int) total;
    return 0;
}