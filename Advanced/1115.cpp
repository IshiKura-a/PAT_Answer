#include <iostream>

class BST {
public:
    int val;
    int height = 0;
    BST *l = nullptr, *r = nullptr;

    explicit BST(int val) : val(val) {}

    int insert(int val) {
        if (val <= this->val) {
            if (l) {
                return l->insert(val);
            } else {
                l = new BST(val);
                l->height = height + 1;
                return l->height;
            }
        } else {
            if (r) {
                return r->insert(val);
            } else {
                r = new BST(val);
                r->height = height + 1;
                return r->height;
            }
        }
    }
};

int level0 = 0, level1 = 0;
int maxHeight = 0;

void transver(BST *node) {
    if (!node) return;
    if (node->height == maxHeight) {
        level0++;
    }
    if (node->height == maxHeight - 1) {
        level1++;
    }
    transver(node->l);
    transver(node->r);
}

int main() {
    int N, val;
    BST *head = nullptr;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> val;
        if (head) {
            maxHeight = std::max(maxHeight, head->insert(val));
        } else {
            head = new BST(val);
        }
    }

    transver(head);
    printf("%d + %d = %d", level0, level1, level1 + level0);

    return 0;
}