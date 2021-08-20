#include <iostream>
#include <set>

#define MAXN 205

bool adjacent[MAXN][MAXN];

int main() {
    int v, e, i, j, m, n;
    scanf("%d%d", &v, &e);

    for (i = 0; i < e; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        adjacent[x][y] = adjacent[y][x] = true;
    }

    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &n);
        std::set<int> clique;
        bool flag = true;
        for (j = 0; j < n; j++) {
            int tmp;
            scanf("%d", &tmp);
            if (flag) {
                for (auto vet: clique) {
                    if (!adjacent[vet][tmp]) {
                        flag = false;
                        break;
                    }
                }
            }
            clique.insert(tmp);
        }
        if (flag) {
            for (j = 1; j <= v && flag; j++) {
                if (clique.find(j) == clique.end()) {
                    bool mFlag = true;
                    for (auto vet: clique) {
                        if (!adjacent[vet][j]) {
                            mFlag = false;
                            break;
                        }
                    }
                    if(mFlag) {
                        flag = false;
                    }
                }
            }
            if (flag) {
                printf("Yes\n");
            } else {
                printf("Not Maximal\n");
            }
        } else {
            printf("Not a Clique\n");
        }
    }
}

