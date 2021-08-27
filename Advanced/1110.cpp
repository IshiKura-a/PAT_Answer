#include <iostream>
#include <vector>
#include <queue>

class Tree {
public:
    int id = -1;
    Tree *l = nullptr, *r = nullptr;
    Tree *father;
};

int main() {
    int N;
    std::cin >> N;
    std::vector<Tree *> nodes(N);
    for (int i = 0; i < N; i++) nodes[i] = new Tree();

    std::string l, r;
    for (int i = 0; i < N; i++) {
        nodes[i]->id = i;
        std::cin >> l >> r;
        if (l != "-") {
            nodes[i]->l = nodes[std::stoi(l)];
            nodes[i]->l->father = nodes[i];
        }
        if (r != "-") {
            nodes[i]->r = nodes[std::stoi(r)];
            nodes[i]->r->father = nodes[i];
        }
    }

    int head = -1;
    for (int i = 0; i < N; i++) {
        if (!nodes[i]->father) {
            head = i;
            break;
        }
    }

    bool isComplete = true, noMoreChildren = false;
    int tail = head;
    std::queue<Tree *> q({nodes[head]});
    while (!q.empty() && isComplete) {
        auto p = q.front();
        if (p->l) {
            q.push(p->l);
            tail = p->l->id;
            if (noMoreChildren) {
                isComplete = false;
                break;
            }
        } else {
            noMoreChildren = true;
        }
        if (p->r) {
            q.push(p->r);
            tail = p->r->id;
            if (noMoreChildren) {
                isComplete = false;
                break;
            }
        } else {
            noMoreChildren = true;
        }
        q.pop();
    }

    if (isComplete) {
        printf("YES %d", tail);
    } else {
        printf("NO %d", head);
    }
    return 0;
}