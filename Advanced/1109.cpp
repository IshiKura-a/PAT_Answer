#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>

class People {
public:
    std::string name;
    int height;

    People(std::string name, int height) : name(std::move(name)), height(height) {}
};

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<People *> v;

    std::string name;
    int height;
    for (int i = 0; i < N; i++) {
        std::cin >> name >> height;
        v.push_back(new People(name, height));
    }
    std::sort(v.begin(), v.end(), [](People *a, People *b) {
        return a->height > b->height || (a->height == b->height && a->name < b->name);
    });

    int n = std::round(N * 1.0 / K);
    std::vector<std::deque<People *>> group;
    for (int i = 0; i < N;) {
        int inc = i == 0 ? (n + N % K) : n;
        std::deque<People *> row;
        for (int j = 0; j < inc; j++) {
            if (j % 2) {
                row.push_front(v[j + i]);
            } else {
                row.push_back(v[j + i]);
            }
        }
        group.push_back(row);
        i += inc;
    }

    for (auto row: group) {
        for (auto p: row) {
            if (p != row.front()) {
                std::cout << " ";
            }
            std::cout << p->name;
        }
        std::cout << std::endl;
    }
    return 0;
}
