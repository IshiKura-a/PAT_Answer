#include <iostream>

#define MAXN 10005

int rank[MAXN];

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int N, K;
    int id;
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        std::cin >> id;
        rank[id] = i;
    }

    std::cin >> K;
    for (int i = 0; i < K; i++) {
        std::cin >> id;
        auto n = rank[id];
        if (n) {
            if (n == 1) {
                printf("%04d: Mystery Award\n", id);
                rank[id] = -1;
            } else if (isPrime(n)) {
                printf("%04d: Minion\n", id);
                rank[id] = -1;
            } else if(n == -1) {
                printf("%04d: Checked\n", id);
            } else {
                printf("%04d: Chocolate\n", id);
                rank[id] = -1;
            }
        } else {
            printf("%04d: Are you kidding?\n", id);
        }
    }
    return 0;
}