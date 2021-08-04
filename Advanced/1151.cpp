#include <iostream>
#include <vector>
#include <unordered_map>

class Tree {
public:
    int val = 0;
    Tree *l = nullptr, *r = nullptr;
};

Tree *generateTree(int inBegin, int inEnd, int preBegin, int preEnd);

std::vector<int> generatePath(int val);

std::vector<int> inOrder, preOrder;
std::unordered_map<int, int> path;

int main() {
    int M, N;
    std::cin >> N >> M;
    int i, tmp;

    for (i = 0; i < M; i++) {
        std::cin >> tmp;
        inOrder.push_back(tmp);
    }
    for (i = 0; i < M; i++) {
        std::cin >> tmp;
        preOrder.push_back(tmp);
    }

    Tree *tree = generateTree(0, M, 0, M);
    path[tree->val] = -1;

    int x, y;
    for (i = 0; i < N; i++) {
        std::cin >> x >> y;
        auto pathX = generatePath(x);
        auto pathY = generatePath(y);

        bool flag = true;
        auto itX = pathX.rbegin(), itY = pathY.rbegin();
        switch ((pathX.empty()) * 2 + (pathY.empty())) {
            case 0:
                for (; itX != pathX.rend() && itY != pathY.rend(); itX++, itY++) {
                    if (*itX != *itY) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    printf("%d is an ancestor of %d.\n", pathX.size() > pathY.size() ? y : x,
                           pathX.size() > pathY.size() ? x : y);
                } else {
                    printf("LCA of %d and %d is %d.\n", x, y, *(--itX));
                }
                break;
            case 1:
                printf("ERROR: %d is not found.\n", y);
                break;
            case 2:
                printf("ERROR: %d is not found.\n", x);
                break;
            case 3:
                printf("ERROR: %d and %d are not found.\n", x, y);
                break;
        }
    }

    return 0;
}

Tree *generateTree(int inBegin, int inEnd, int preBegin, int preEnd) {
    if (inBegin >= inEnd) return nullptr;
    Tree *t = new Tree();
    t->val = preOrder[preBegin];
    auto it = inBegin;
    while (inOrder[it] != preOrder[preBegin] && it != inEnd) it++;
    t->l = generateTree(inBegin, it,
                        preBegin + 1, preBegin + 1 + (it - inBegin));
    if (t->l) path.insert(std::make_pair(t->l->val, t->val));
    t->r = generateTree(it + 1, inEnd,
                        preBegin + 1 + (it - inBegin), preEnd);
    if (t->r) path.insert(std::make_pair(t->r->val, t->val));
    return t;
}

std::vector<int> generatePath(int val) {
    if (path.find(val) == path.end()) return {};
    else {
        std::vector<int> res;
        int i = val;
        do {
            res.push_back(i);
            i = path[i];
        } while (i != -1);
        return res;
    }
}
