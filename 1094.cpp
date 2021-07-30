#include <iostream>
#include <iomanip>
#include <cmath>

bool isPrime(int n);

int main() {
    int L, K, i;
    std::string s;
    std::cin >> L >> K >> s;

    int module = 1;
    for (i = 1; i < K; i++) module *= 10;
    int n = stoi(s.substr(0, K));
    i = 0;
    bool flag = true;
    if (L >= K) {
        do {
            if (isPrime(n)) {
                std::cout << std::setw(K) << std::setfill('0') << n;
                flag = false;
                break;
            }
        } while (i + K <= L && (n = n % module * 10 + s[i++ + K] - '0'));
    }
    if (flag) std::cout << 404;

    return 0;
}

bool isPrime(int n) {
    int i;
    if (n == 0 || n == 1) return false;
    if (n == 2) return true;
    if (!(n & 1)) return false;
    for (i = 3; i < sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }

    return true;
}