#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAXN 105

int tellLie(int n, int i, int j) {
    if (n == i || n == j) return -1;
    else return 1;
}

int sign(int n) {
    if (n > 0) return 1;
    else if (n < 0) return -1;
    else return 0;
}

bool isWolfTellLie(int wolfX, int wolfY, int lierX, int lierY) {
    return wolfX == lierY || wolfY == lierX || (wolfX == lierX && wolfY != lierY) || (wolfX != lierX && wolfY == lierY);
}

int main() {
    int isWolf[MAXN];
    int N, i, tmp;
    std::vector<int> stmt;
    std::cin >> N;
    for (i = 0; i < N; i++) {
        std::cin >> tmp;
        stmt.push_back(tmp);
    }

    int j, k;
    bool flag;
    std::vector<int> sol = {N + 1, N + 1};
    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            memset(isWolf, 0, sizeof(isWolf));
            flag = true;
            for (k = 0; k < N; k++) {
                if (isWolf[abs(stmt[k])] && isWolf[abs(stmt[k])] != tellLie(k, i, j) * sign(stmt[k])) {
                    flag = false;
                    break;
                }
                isWolf[abs(stmt[k])] = tellLie(k, i, j) * sign(stmt[k]);
            }

            std::vector<int> wolves;
            if (flag) {
                for (k = 1; k <= N; k++) {
                    if (isWolf[k] < 0) {
                        wolves.push_back(k);
                    }
                }
                if (wolves.size() < 2) {
                    std::vector<int> candidate;
                    for (k = N; k > 0; k--) {
                        if (isWolf[k] == 0) {
                            candidate.push_back(k);
                        }
                    }
                    while(wolves.size() < 2 && !candidate.empty()) {
                        wolves.push_back(candidate[candidate.size()-1]);
                        candidate.pop_back();
                    }
                }
                std::sort(wolves.begin(), wolves.end());
                if (wolves.size() == 2 && isWolfTellLie(wolves[0], wolves[1], i+1, j+1)) {
                    if (sol[0] > wolves[0] || (sol[0] == wolves[0] && sol[1] > wolves[1])) {
                        sol = wolves;
                    }
                }
            }
        }
    }

    if (sol[0] == N + 1 && sol[1] == N + 1) {
        std::cout << "No Solution\n";
    } else {
        std::cout << sol[0] << " " << sol[1];
    }

    return 0;
}
