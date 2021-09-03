#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

class Node {
public:
    int val = 0;
    int l = -1, r = -1;
};

int cnt = 0;
std::vector<Node> v;
std::vector<int> a;

void inOrder(int cur) {
    if (cur != -1) {
        inOrder(v[cur].l);
        v[cur].val = a[cnt++];
        inOrder(v[cur].r);
    }
}

int main() {
    int N;
    std::cin >> N;
    v = std::vector<Node>(N);
    a = std::vector<int>(N);
    for (int i = 0; i < N; i++) {
        std::cin >> v[i].l >> v[i].r;
    }

    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    inOrder(0);

    std::queue<int> q({0});
    printf("%d", v[0].val);
    while (!q.empty()) {
        auto front = q.front();
        if (v[front].l >= 0) {
            printf(" %d", v[v[front].l].val);
            q.push(v[front].l);
        }
        if (v[front].r >= 0) {
            printf(" %d", v[v[front].r].val);
            q.push(v[front].r);
        }
        q.pop();
    }
    return 0;
}
