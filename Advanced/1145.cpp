#include <iostream>
#include <cmath>

#define MAXN 10009
int N, M, MSize;
int hash[MAXN];

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    int i;
    for (i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int getNearestPrime(int n) {
    while (true) {
        if (isPrime(n)) return n;
        else n++;
    }
}

int quadraticProbing(int n) {
    int i = 1;
    while ((n + i * i) % MSize != n % MSize && hash[(n + i * i) % MSize]) {
        i++;
    }

    if ((n + i * i) % MSize != n % MSize) return (n + i * i) % MSize;
    else return -1;
}

int hashF(int val) {
    int i;
    for (i = 0; i < MSize; i++) {
        if (!hash[(val + i * i) % MSize]) return (val + i * i) % MSize;
    }
    return -1;
}

int find(int val) {
    int i;
    for (i = 0; i < MSize; i++) {
        if (hash[(val + i * i) % MSize] == val || !hash[(val + i * i) % MSize]) return i + 1;
    }
    return i + 1;
}

int main() {
    std::cin >> MSize >> N >> M;
    MSize = getNearestPrime(MSize);

    int i, val;
    for (i = 0; i < N; i++) {
        std::cin >> val;
        int pos = hashF(val);
        if (pos < 0) printf("%d cannot be inserted.\n", val);
        else hash[pos] = val;
    }

    int cnt = 0;
    for (i = 0; i < M; i++) {
        std::cin >> val;
        cnt += find(val);
    }
    printf("%.1f", cnt * 1.0 / M);

    return 0;
}