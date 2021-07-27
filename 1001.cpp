#include <iostream>

int main() {
    int n, cnt = 0;
    std::cin >> n;
    while (n != 1) {
        if (n & 1) {
            n = (3 * n + 1) / 2;
        } else n /= 2;
        cnt++;
    }
    std::cout << cnt;
    return 0;
}
