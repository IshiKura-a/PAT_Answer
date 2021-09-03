#include <iostream>
#include <cmath>

typedef long long ll;

int main() {
    ll N;
    std::cin >> N;

    ll maxN = 0, start;
    for (ll i = (ll) sqrt(N); i > 1; i--) {
        ll tmp = N;
        ll j = i;
        while (tmp != 1 && !(tmp % j) && j > 1) {
            tmp /= j;
            j--;
        }
        j++;
        if (maxN <= i - j + 1) {
            maxN = i - j + 1;
            start = i;
        }
    }
    if (maxN) {
        std::cout << maxN << std::endl;
        for (ll i = start - maxN + 1; i <= start; i += 1) {
            if (i != start - maxN + 1) {
                printf("*");
            }
            std::cout << i;
        }
    } else {
        std::cout << 1 << std::endl << N;
    }
}
