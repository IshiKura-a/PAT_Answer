#include <iostream>
#include <vector>
#include <queue>

bool first = true;
class Node {
public:
    int id = 0;
    int l = -1, r = -1;
    bool isHead = true;
};

void dfs(int node, int head, std::vector<Node> tree) {
    if (tree[node].l >= 0) {
        dfs(tree[node].l, head, tree);
    }
    if(!first) printf(" ");
    first = false;
    printf("%d", node);
    if (tree[node].r >= 0) {
        dfs(tree[node].r, head, tree);
    }
}

int main() {
    int N;
    std::cin >> N;
    std::vector<Node> tree(N);

    std::string l, r;
    for (int i = 0; i < N; i++) {
        std::cin >> l >> r;
        if (l != "-") {
            tree[i].r = std::stoi(l);
            tree[tree[i].r].isHead = false;
        }
        if (r != "-") {
            tree[i].l = std::stoi(r);
            tree[tree[i].l].isHead = false;
        }
    }

    int head;
    for (int i = 0; i < N; i++) {
        if (tree[i].isHead) {
            head = i;
            break;
        }
    }

    std::queue<int> q({head});
    printf("%d", head);
    while (!q.empty()) {
        auto front = q.front();
        if (tree[front].l >= 0) {
            printf(" %d", tree[front].l);
            q.push(tree[front].l);
        }
        if (tree[front].r >= 0) {
            printf(" %d", tree[front].r);
            q.push(tree[front].r);
        }
        q.pop();
    }
    printf("\n");

    dfs(head, head, tree);
    return 0;
}