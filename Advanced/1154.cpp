#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

#define MAXN 10005

int main() {
    std::set<int> adjacent[MAXN];
    std::map<int, std::vector<int>> coloring;

    int N, M, K, i, j, k;
    std::cin >> N >> M;
    for (i = 0; i < M; i++) {
        int x, y;
        std::cin >> x >> y;
        adjacent[std::min(x, y)].insert(std::max(x, y));
    }

    std::cin >> K;
    int tmp;
    for (i = 0; i < K; i++) {
        coloring.clear();
        for (j = 0; j < N; j++) {
            std::cin >> tmp;
            auto set = coloring.find(tmp);
            if (set != coloring.end()) {
                set->second.push_back(j);
            } else {
                coloring.insert(std::make_pair(tmp, (std::vector<int>) {j}));
            }
        }
        bool flag = true;
        for (const auto &set: coloring) {
            auto vector = set.second;
            sort(vector.begin(), vector.end());
            for (j = 0; j < vector.size(); j++) {
                for (k = j + 1; k < vector.size(); k++) {
                    if (adjacent[vector[j]].find(vector[k]) != adjacent[vector[j]].end()) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        printf("%s\n", flag ? (std::to_string(coloring.size()) + "-coloring").c_str() : "No");
    }
}

