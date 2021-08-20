#include <iostream>

#define MAXN 25

class Node {
public:
    std::string val;
    int l = -1, r = -1;
    int father = -1;

    Node() {}

    Node(std::string val, int l, int r, int father) : val(std::move(val)), l(l), r(r), father(father) {}
};

int N, start = 1;
Node node[MAXN];

void inOrder(int n);

int main() {
    std::cin >> N;
    std::fill(node + 1, node + N + 1, Node());
    for (int i = 1; i <= N; i++) {
        std::cin >> node[i].val >> node[i].l >> node[i].r;
        node[node[i].l].father = i;
        node[node[i].r].father = i;
    }

    while (node[start].father != -1) start++;

    inOrder(start);
    return 0;
}

void inOrder(int n) {
    if (n != -1) {
        int l = node[n].l;
        int r = node[n].r;

        if ((l != -1 || r != -1) && n != start) {
            std::cout << "(";
        }
        inOrder(l);
        std::cout << node[n].val;
        inOrder(r);
        if ((l != -1 || r != -1) && n != start) {
            std::cout << ")";
        }
    }
}