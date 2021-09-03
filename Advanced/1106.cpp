#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

const int MAXN = 1e5 + 5;

class Distributor {
public:
    int id;
    int height = MAXN;
    std::vector<int> to;

    Distributor(int id, int size) : id(id) {
        to.reserve(size);
    }
};

int main() {
    int N, K;
    double r, P;
    std::cin >> N >> P >> r;

    std::vector<Distributor *> distributor;
    std::vector<Distributor *> retailer;
    distributor.reserve(N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &K);
        distributor.push_back(new Distributor(i, K));
        int to;
        if (!K) {
            retailer.push_back(distributor[i]);
        }
        for (int j = 0; j < K; j++) {
            scanf("%d", &to);
            distributor[i]->to.push_back(to);
        }
    }

    std::vector<int> depth(N);
    std::fill(depth.begin(), depth.end(), MAXN);

    std::queue<Distributor *> q({distributor[0]});
    int curHeight = -1;
    while (!q.empty()) {
        curHeight++;
        int cnt = q.size(), j = 0;
        for (j = 0; j < cnt; j++) {
            auto front = q.front();
            front->height = curHeight;
            for (auto item: front->to) {
                q.push(distributor[item]);
            }
            q.pop();
        }
    }

    int minHeight = MAXN;
    int cnt = 0;
    for (auto i: retailer) {
        if (i->height < minHeight) {
            minHeight = i->height;
            cnt = 1;
        } else if (i->height == minHeight) {
            cnt++;
        }
    }

    double minPrice = P * pow((1 + 0.01 * r), minHeight);
    printf("%.4f %d", minPrice, cnt);
    return 0;
}