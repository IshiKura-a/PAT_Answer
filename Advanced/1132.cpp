#include <iostream>

typedef unsigned long ul;

ul toUL(std::string s) {
    ul n = 0;
    for (auto c: s) {
        n *= 10;
        n += c - '0';
    }
    return n;
}

int main() {
    int N;
    int i;
    std::cin >> N;
    for (i = 0; i < N; i++) {
        std::string n;
        std::cin >> n;
        ul before = toUL(n.substr(0, n.size() / 2));
        ul after = toUL(n.substr(n.size() / 2, n.size() / 2));
        ul tot = toUL(n);
        if (after != 0 && tot % (before * after) == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}