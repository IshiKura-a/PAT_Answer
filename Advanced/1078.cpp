#include <iostream>
#include <vector>

bool isPrime(int n) {
    if (n <= 1) return false;
    else if (n == 2) return true;
    else {
        for (int i = 2; i * i <= n; i++) {
            if (!(n % i)) {
                return false;
            }
        }
        return true;
    }
}

int getPrime(int n) {
    while (!isPrime(n)) n++;
    return n;
}

int main() {
    int mSize, n;
    std::cin >> mSize >> n;
    mSize = getPrime(mSize);

    std::vector<int> hash(mSize, 0);

    int num;
    for (int i = 0; i < n; i++) {
        std::cin >> num;
        int place = -1;
        for (int j = 0; j < mSize; j++) {
            if (!hash[(num + j * j) % mSize]) {
                place = (num + j * j) % mSize;
                hash[(num + j * j) % mSize] = num;
                break;
            }
        }
        if (i) printf(" ");
        std::cout << (place == -1 ? "-" : std::to_string(place));
    }

    return 0;
}