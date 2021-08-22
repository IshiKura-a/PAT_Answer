#include <iostream>
#include <vector>
#include <set>

#define MAXN 100005

bool party[MAXN];

int main() {
    int N, M;
    std::cin >> N;

    int x, y;
    std::vector<std::pair<int, int>> couple;
    for (int i = 0; i < N; i++) {
        std::cin >> x >> y;
        couple.emplace_back(x, y);
    }

    std::cin >> M;
    std::fill(party, party + MAXN, false);
    for (int i = 0; i < M; i++) {
        std::cin >> x;
        party[x] = true;
    }

    for (auto c: couple) {
        if (party[c.first] && party[c.second]) {
            party[c.first] = party[c.second] = false;
        }
    }

    int cnt = 0;
    std::vector<int> care;
    for (int i = 0; i <= 99999; i++) {
        if (party[i]) {
            care.push_back(i);
            cnt++;
        }
    }

    printf("%d\n", care.size());
    for (int i = 0; i < care.size(); i++) {
        if (i) printf(" ");
        printf("%05d", care[i]);
    }
    return 0;
}