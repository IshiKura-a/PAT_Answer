#include <iostream>
#include <vector>
#include <queue>

class People {
public:
    int generation = 1;
    std::vector<int> children;
};

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<People *> family(N + 1);
    std::vector<int> population(N + 1);
    std::vector<bool> notRoot(N + 1, false);

    for (int i = 1; i <= N; i++) {
        family[i] = new People();
    }
    int id, k, n;
    for (int i = 0; i < M; i++) {
        std::cin >> id >> k;

        for (int j = 0; j < k; j++) {
            std::cin >> n;
            notRoot[n] = true;
            family[id]->children.push_back(n);
        }
    }

    int root;
    for (int i = 1; i <= N; i++) {
        if (!notRoot[i]) {
            root = i;
            break;
        }
    }

    std::queue<int> q({root});
    while (!q.empty()) {
        auto front = family[q.front()];
        for (auto i: front->children) {
            auto node = family[i];
            node->generation = front->generation + 1;
            q.push(i);
        }
        population[front->generation]++;
        q.pop();
    }

    int max = 1, maxN = population[1];
    for (int i = 2; i <= N; i++) {
        if (population[i] > maxN) {
            max = i;
            maxN = population[i];
        }
    }
    printf("%d %d", maxN, max);
    return 0;
}