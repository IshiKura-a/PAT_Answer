#include <iostream>
#include <queue>
#include <set>

enum Attr {
    red = 0,
    black = 1,
    };

class Tree {
public:
    int val = 0;
    int numBlack = 0;
    Attr attr = black;
    Tree *l = nullptr, *r = nullptr;
    Tree *father = nullptr;

    Tree(int val, Attr attr, int numBlack) : val(val), attr(attr), numBlack(numBlack + (attr == black)) {}

    bool build(int val, Attr attr) {
        if (val < this->val) {
            if (this->l) return this->l->build(val, attr);
            else {
                this->l = new Tree(val, attr, this->numBlack);
                return this->attr != red || attr != red;
            }
        } else {
            if (this->r) return this->r->build(val, attr);
            else {
                this->r = new Tree(val, attr, this->numBlack);
                return this->attr != red || attr != red;
            }
        }
    }
};

int main() {
    int N, n;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> n;
        Tree *cur = nullptr, *head = nullptr;
        bool flag = true;
        for (int j = 0; j < n; j++) {
            int tmp;
            std::cin >> tmp;
            int val = abs(tmp);
            if (j) {
                flag &= head->build(val, val == tmp ? black : red);
            } else {
                head = new Tree(val, val == tmp ? black : red, 0);
                flag = head->attr != red;
            }
        }
        if (flag) {
            std::queue<Tree *> q;
            std::set<int> numBlack;
            q.push(head);
            while (flag && !q.empty()) {
                auto front = q.front();
                if (front->l) {
                    q.push(front->l);
                } else {
                    numBlack.insert(front->numBlack + 1);
                    if (numBlack.size() != 1) {
                        flag = false;
                        break;
                    }
                }
                if (front->r) {
                    q.push(front->r);
                } else {
                    numBlack.insert(front->numBlack + 1);
                    if (numBlack.size() != 1) {
                        flag = false;
                        break;
                    }
                }
                q.pop();
            }
            printf("%s\n", flag ? "Yes" : "No");
        } else {
            printf("No\n");
        }
    }
    return 0;
}