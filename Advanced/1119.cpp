#include <iostream>
#include <vector>

std::vector<int> preOrder, postOrder, inOrder;
bool unique = true;

void getIn(int preBegin, int preEnd, int postBegin, int postEnd);

int main() {
    int N, x;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> x;
        preOrder.push_back(x);
    }
    for (int i = 0; i < N; i++) {
        std::cin >> x;
        postOrder.push_back(x);
    }

    getIn(0, N - 1, 0, N - 1);
    std::cout << (unique ? "Yes\n" : "No\n");
    for (int i = 0; i < inOrder.size(); i++) {
        if (i) printf(" ");
        printf("%d", inOrder[i]);
    }
    printf("\n");
    return 0;
}

void getIn(int preBegin, int preEnd, int postBegin, int postEnd) {
    if (preBegin == preEnd) {
        inOrder.push_back(preOrder[preBegin]);
        return;
    }

    int i = preBegin + 1;
    while (i <= preEnd && preOrder[i] != postOrder[postEnd - 1]) i++;
    if (i - preBegin > 1) {
        getIn(preBegin + 1, i - 1, postBegin, postBegin + (i - preBegin - 2));
    } else {
        unique = false;
    }
    inOrder.push_back(postOrder[postEnd]);
    getIn(i, preEnd, postBegin + (i - preBegin - 1), postEnd - 1);
}