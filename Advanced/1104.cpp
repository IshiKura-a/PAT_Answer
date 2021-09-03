#include <iostream>

int main() {
    int N;

    std::cin >> N;
    long double n, res = 0;

    for (int i = 1; i <= N; i++) {
        std::cin >> n;
        res += n * i * (N - i + 1);
    }
    printf("%.2llf", res);
    return 0;
}