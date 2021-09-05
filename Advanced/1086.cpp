#include <iostream>
#include <stack>

class Node {
public:
    int val = 0;
    Node *l = nullptr, *r = nullptr, *father = nullptr;

    Node(int val) : val(val) {}
};

void postOrder(Node *n) {
    if (n) {
        postOrder(n->l);
        postOrder(n->r);
        printf("%d ", n->val);
    }
}

int main() {
    int n, val;
    std::string cmd;
    std::stack<Node *> stack;

    std::cin >> n;
    Node *head = nullptr, *cur;
    for (int i = 0; i < n * 2; i++) {
        std::cin >> cmd;
        if (cmd == "Push") {
            std::cin >> val;
            Node *p = new Node(val);
            if (!i) {
                head = p;
                cur = p;
            } else {
                if (cur->l) {
                    cur->r = p;
                } else {
                    cur->l = p;
                }
                p->father = cur;
                cur = p;
            }
            stack.push(p);
        } else {
            cur = stack.top();
            stack.pop();
        }
    }

    postOrder(head->l);
    postOrder(head->r);
    printf("%d", head->val);
}
