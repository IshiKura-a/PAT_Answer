#include <iostream>
#include <queue>

class AVLTree {
public:
    int val;
    int lh = 0, rh = 0;
    AVLTree *l = nullptr, *r = nullptr;

    explicit AVLTree(int val) : val(val) {}

    AVLTree *insert(int val) {
        if (val < this->val) {
            if (l) {
                this->l = l->insert(val);
                lh = std::max(l->lh, l->rh) + 1;
            } else {
                l = new AVLTree(val);
                lh = 1;
            }
        } else {
            if (r) {
                this->r = r->insert(val);
                rh = std::max(r->lh, r->rh) + 1;
            } else {
                r = new AVLTree(val);
                rh = 1;
            }
        }
        if (this->lh >= this->rh + 2) {
            if (this->l->lh > this->l->rh) {
                return rRot();
            } else {
                this->l = this->l->lRot();
                return rRot();
            }
        } else if (this->rh >= this->lh + 2) {
            if (this->r->rh > this->r->lh) {
                return lRot();
            } else {
                this->r = this->r->rRot();
                return lRot();
            }
        } else {
            return this;
        }
    }

    AVLTree *rRot() {
        auto left = this->l;
        this->l = left->r;
        left->r = this;
        this->lh = this->l ? std::max(this->l->lh, this->l->rh) + 1 : 0;
        left->rh = this->rh + 1;
        return left;
    }

    AVLTree *lRot() {
        auto right = this->r;
        this->r = right->l;
        right->l = this;
        this->rh = this->r ? std::max(this->r->lh, this->r->rh) + 1 : 0;
        right->lh = this->lh + 1;
        return right;
    }
};

int main() {
    int N, val;
    std::cin >> N;

    AVLTree *head;
    for (int i = 0; i < N; i++) {
        std::cin >> val;
        if (i) {
            head = head->insert(val);
        } else {
            head = new AVLTree(val);
        }
    }

    bool compeleteFlag = true, noChildrenFlag = false;
    std::queue<AVLTree *> q({head});
    std::cout << head->val;
    while (!q.empty()) {
        auto node = q.front();
        if (node->l) {
            q.push(node->l);
            std::cout << " " << node->l->val;
            if (noChildrenFlag) {
                compeleteFlag = false;
            }
        } else {
            noChildrenFlag = true;
        }
        if (node->r) {
            q.push(node->r);
            std::cout << " " << node->r->val;
            if (noChildrenFlag) {
                compeleteFlag = false;
            }
        } else {
            noChildrenFlag = true;
        }
        q.pop();
    }
    std::cout << (compeleteFlag ? "\nYES" : "\nNO");
    return 0;
}