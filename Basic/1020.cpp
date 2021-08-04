#include <iostream>
#include <algorithm>
#include <vector>

class MoonCake {
public:
    double capacity = 0;
    double totalPrice = 0;
    double unitPrice = 0;
};

int main() {
    int N, D;
    int i;
    std::vector<MoonCake *> cakes;

    std::cin >> N >> D;
    for (i = 0; i < N; i++) {
        cakes.push_back(new MoonCake());
        std::cin >> cakes[i]->capacity;
    }
    for (i = 0; i < N; i++) {
        std::cin >> cakes[i]->totalPrice;
        cakes[i]->unitPrice = cakes[i]->totalPrice / cakes[i]->capacity;
    }
    std::sort(cakes.begin(), cakes.end(), [](MoonCake *a, MoonCake *b) {
        return a->unitPrice > b->unitPrice || (a->unitPrice == b->unitPrice && a->capacity > b->capacity);
    });

    double value = 0;
    for (i = 0; i < N && D != 0; i++) {
        if (cakes[i]->capacity <= D) {
            value += cakes[i]->totalPrice;
            D -= cakes[i]->capacity;
        } else {
            value += cakes[i]->unitPrice * D;
            D = 0;
        }
    }
    printf("%.2f", value);
}