#include <iostream>
#include <cstring>

#define MAXN 1005

int main() {
    int sale[MAXN];
    int N, M, i, j;
    memset(sale, 0, sizeof(sale));

    std::cin >> N >> M;
    int tmp;
    int maxSale = 0;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            std::cin >> tmp;
            sale[j] += tmp;
            if (sale[j] > maxSale) {
                maxSale = sale[j];
            }
        }
    }

    std::cout << maxSale << std::endl;
    bool flag = false;
    for (i = 0; i < N; i++) {
        if (sale[i] == maxSale) {
            if (flag) std::cout << " ";
            flag = true;
            std::cout << i + 1;
        }
    }
}

