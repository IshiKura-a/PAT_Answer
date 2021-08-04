#include <iostream>

std::string comp(double me, double n) {
    if (n > me) return " Cong";
    else if (n == me) return " Ping";
    else return " Gai";
}

int main() {
    int M, X, Y, i, j;
    double k;
    std::cin >> M >> X >> Y;
    for (i = 99; i >= 10; i--) {
        j = i % 10 * 10 + i / 10;
        if (abs(i - j) * Y == j * X) {
            k = j * 1.0 / Y;
            std::cout << i << comp(M, i) << comp(M, j) << comp(M, k);
            break;
        }
    }

    if (i < 10) std::cout << "No Solution";
    return 0;
}
