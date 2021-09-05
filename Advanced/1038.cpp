#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> v(n);

    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    std::sort(v.begin(), v.end(), [](std::string a, std::string b) {
        if (a.length() < b.length()) {
            for (int i = 0; i < b.length(); i += a.length()) {
                if (a < b.substr(i, a.length())) {
                    return true;
                } else if (a > b.substr(i, a.length())) {
                    return false;
                }
            }
            return false;
        } else if (a.length() > b.length()) {
            for (int i = 0; i < a.length(); i += b.length()) {
                if (a.substr(i, b.length()) < b) {
                    return true;
                } else if (a.substr(i, b.length()) > b) {
                    return false;
                }
            }
            return false;
        } else {
            return a < b;
        }
    });

    bool isZero = true;
    for (const auto &str: v) {
        for (auto c: str) {
            if (isZero) {
                if (c != '0') {
                    isZero = false;
                    printf("%c", c);
                }
            } else {
                printf("%c", c);
            }
        }
    }
    if (isZero) printf("0");
    return 0;
}