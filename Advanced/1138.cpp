#include <iostream>
#include <vector>

std::vector<int> pre;
std::vector<int> in;

int find(int preBegin, int preEnd, int inBegin, int inEnd);

int main() {
    int N, i, tmp;
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &tmp);
        pre.push_back(tmp);
    }
    for (i = 0; i < N; i++) {
        scanf("%d", &tmp);
        in.push_back(tmp);
    }

    std::cout << find(0, N, 0, N);
    return 0;
}

int find(int preBegin, int preEnd, int inBegin, int inEnd) {
    if (preEnd - preBegin <= 2) {
        if (preEnd - preBegin == 2) {
            return pre[preBegin + 1];
        } else {
            return pre[preBegin];
        }
    }
    int i = 0;
    while (i + inBegin != inEnd && in[i + inBegin] != pre[preBegin]) {
        i++;
    }
    return i ?
           find(preBegin + 1, preBegin + i + 1, inBegin, inBegin + i) :
           find(preBegin + i + 1, preEnd, inBegin + i + 1, inEnd);

}