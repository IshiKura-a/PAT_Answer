#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

enum Dir {
    Right = 0,
    Down = 1,
    Left = 2,
    Up = 3,
};

int main() {
    int N;

    std::cin >> N;
    std::vector<int> v(N);
    for (int i = 0; i < N; i++) {
        std::cin >> v[i];
    }

    std::sort(v.begin(), v.end(), std::greater<>());
    int m = (int) std::ceil(sqrt(N));
    while (N % m) {
        m++;
    }
    int n = N / m;

    int cnt = 0;
    int x = 0, y = -1;
    Dir dir = Right;
    std::vector<int> matrix(N);
    for (int i = 0; i < N; i++) {
        if (x == cnt && y == cnt - 1) {
            dir = Right;
        } else if (x == cnt && y == n - cnt - 1) {
            dir = Down;
        } else if (x == m - cnt - 1 && y == n - cnt - 1) {
            dir = Left;
        } else if (x == m - cnt - 1 && y == cnt) {
            dir = Up;
            cnt++;
        }

        switch (dir) {
            case Right:
                y++;
                break;
            case Down:
                x++;
                break;
            case Left:
                y--;
                break;
            case Up:
                x--;
                break;
        }

        matrix[x * n + y] = v[i];
    }

    for (int i = 0; i < N; i++) {
        if (i % n)
            printf(" ");
        printf("%d", matrix[i]);
        if (i % n == n - 1)
            printf("\n");
    }

    return 0;
}