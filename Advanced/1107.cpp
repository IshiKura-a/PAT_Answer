#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

const int MAXN = 1005;

int cluster[MAXN];
double count[MAXN];

void makeSet(int hobby) {
    if (!cluster[hobby]) {
        cluster[hobby] = hobby;
    }
}

int findSet(int hobby) {
    if (hobby != cluster[hobby]) {
        return cluster[hobby] = findSet(cluster[hobby]);
    } else {
        return hobby;
    }
}

void unionSet(int a, int b) {
    int setA = findSet(a);
    int setB = findSet(b);

    if (setA < setB) {
        cluster[setB] = setA;
    } else {
        cluster[setA] = setB;
    }
}

int main() {
    int N, M;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        scanf("%d:", &M);
        int prev, cur;
        for (int j = 0; j < M; j++) {
            std::cin >> cur;
            makeSet(cur);
            count[cur] += 1.0 / M;
            if (j) {
                unionSet(prev, cur);
            }
            prev = cur;
        }
    }

    std::map<int, double> clusterCount;
    for (int i = 1; i <= 1000; i++) {
        int c = findSet(i);
        if (c) {
            clusterCount[c] += count[i];
        }
    }

    std::vector<double> v;
    for (auto i: clusterCount) {
        if (int(i.second) > 0) {
            v.push_back(i.second);
        }
    }
    std::cout << v.size();

    std::sort(v.begin(), v.end(), std::greater<>());
    for (int i = 0; i < v.size(); i++) {
        printf("%s", i ? " " : "\n");
        std::cout << int(v[i]);
    }
    return 0;
}