#include <iostream>
#include <vector>
#include <cmath>

int N, P, K;
std::vector<int> cur;
std::vector<int> optimal;
std::vector<int> power;
std::vector<int> root;

int optEleSum = 0;
int curSum = 0;
int curEleSum = 0;
bool flag = false;

int fastPower(int n, int p) {
    if (p == 1) return n;
    if (p == 0) return 1;
    int res = fastPower(n, p / 2);
    if (p % 2) {
        return res * res * n;
    } else {
        return res * res;
    }
}

int getPower(int n) {
    if (power[n]) return power[n];
    else return power[n] = (int) fastPower(n, P);
}

int getRoot(int n) {
    if (root[n]) return root[n];
    else return root[n] = (int) pow(n, 1.0 / P);
}

void dfs(int step) {
    if (step >= K) {
        if (curSum < N) {
            flag = false;
            return;
        } else if (curSum == N) {
            if (curEleSum > optEleSum) {
                optEleSum = curEleSum;
                optimal = cur;
            } else if (curEleSum == optEleSum) {
                for (int i = 0; i < K; i++) {
                    if (cur[i] > optimal[i]) {
                        optimal = cur;
                        break;
                    } else if (cur[i] < optimal[i]) {
                        break;
                    }
                }
            }
        }
    } else {
        if (curSum >= N || flag) return;

        int upLimit = getRoot(N - curSum - (K - step - 1));
        int downLimit = getRoot((N - curSum) / (N - step));
        if (step) {
            upLimit = std::min(upLimit, cur[step - 1]);
        }

        for (int i = upLimit; i >= downLimit && i > 0; i--) {
            cur[step] = i;
            int res = getPower(i);
            curSum += res;
            curEleSum += i;
            dfs(step + 1);
            curEleSum -= i;
            curSum -= res;
        }
    }
}

int main() {
    std::cin >> N >> K >> P;
    power = std::vector<int>(405, 0);
    root = std::vector<int>(405, 0);
    cur = std::vector<int>(K);
    dfs(0);

    if (optimal.empty()) {
        printf("Impossible");
    } else {
        printf("%d", N);
        for (int i = 0; i < optimal.size(); i++) {
            if (i) printf(" + ");
            else printf(" = ");
            printf("%d^%d", optimal[i], P);
        }
    }

    return 0;
}