#include <iostream>
#include <cmath>

int findShield(int n, int digit);

int getDigit(int n);

int main() {
    int N;
    std::cin >> N;

    int i;
    for (i = 0; i < N; i++) {
        int k;
        std::cin >> k;
        int res = findShield(k, getDigit(k));
        if (res < 0) {
            std::cout << "No\n";
        } else {
            std::cout << res << " " << k * k * res << std::endl;
        }
    }
}

int getDigit(int n) {
    if (n < 10) return 1;
    else return (int) floor(log10(n)) + 1;
}

int findShield(int k, int digit) {
    int i;
    for (i = 0; i < 10; i++) {
        int nk2 = k * k * i;
        std::string s = std::to_string(nk2);
        if (s.size() >= digit && stoi(s.substr(s.size() - digit, digit)) == k) {
            break;
        }
    }

    if (i == 10) return -1;
    else return i;
}