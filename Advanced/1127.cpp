#include <iostream>
#include <vector>
#include <deque>

class Tree {
public:
    int val;
    Tree *l = nullptr, *r = nullptr;

    Tree(int val) : val(val) {}
};

std::vector<int> inOrder;
std::vector<int> postOrder;

Tree *buildTree(int inBegin, int inEnd, int postBegin, int postEnd);

int main() {
    int N;
    std::cin >> N;

    int node;
    for (int i = 0; i < N; i++) {
        std::cin >> node;
        inOrder.push_back(node);
    }

    for (int i = 0; i < N; i++) {
        std::cin >> node;
        postOrder.push_back(node);
    }

    Tree *head = buildTree(0, N, 0, N);
    std::deque<Tree *> queue;
    printf("%d", head->val);
    queue.push_back(head);
    bool dir = false;
    while (!queue.empty()) {
        std::deque<Tree *> q;
        while (!queue.empty()) {
            if(dir) {
                auto back = queue.back();
                if (back->r) {
                    q.push_front(back->r);
                    printf(" %d", back->r->val);
                }
                if (back->l) {
                    q.push_front(back->l);
                    printf(" %d", back->l->val);
                }
                queue.pop_back();
            } else {
                auto front = queue.front();
                if (front->l) {
                    q.push_back(front->l);
                    printf(" %d", front->l->val);
                }
                if (front->r) {
                    q.push_back(front->r);
                    printf(" %d", front->r->val);
                }
                queue.pop_front();
            }
        }
        queue = q;
        dir = !dir;
    }

    return 0;
}

Tree *buildTree(int inBegin, int inEnd, int postBegin, int postEnd) {
    if (inBegin == inEnd) {
        return nullptr;
    }
    int head = postOrder[postEnd - 1];
    int i = inBegin;
    while (i != inEnd && inOrder[i] != head) {
        i++;
    }

    Tree *p = new Tree(head);
    p->l = buildTree(inBegin, i, postBegin, postBegin + i - inBegin);
    p->r = buildTree(i + 1, inEnd, postBegin + i - inBegin, postEnd - 1);

    return p;
}